#include <array>
#include <cassert>
#include <string_view>

struct MinutesLeft
{
    int value;
};

struct Client
{
    std::string_view label;
    MinutesLeft hairCompletion;
};

struct Worker
{
    Client* assignedClient{ nullptr };
};

struct Shop
{
    std::array<Client*, 4> queue{};
    std::array<Worker, 3> workers{};
};

Client** find_free_slot(Shop& shop)
{
    for (auto& slot : shop.queue)
    {
        if (slot == nullptr)
        {
            return &slot;
        }
    }

    return nullptr;
}

enum class AddClientResult
{
    Added,
    FailedQueueFull,
};

AddClientResult add_client(Shop& shop, Client* client)
{
    assert(client != nullptr);

    Client** slot{ find_free_slot(shop) };

    if (slot == nullptr)
    {
        return AddClientResult::FailedQueueFull;
    }

    *slot = client;

    return AddClientResult::Added;
}

Client** find_taken_slot(Shop& shop)
{
    for (auto& slot : shop.queue)
    {
        if (slot != nullptr)
        {
            return &slot;
        }
    }

    return nullptr;
}

Client* take_first_waiting(Shop& shop)
{
    Client** slot{ find_taken_slot(shop) };

    if (slot == nullptr)
    {
        return nullptr;
    }

    Client* found{ *slot };
    *slot = nullptr;

    return found;
}

Client* find_assigned_client(const Shop& shop)
{
    for (const auto& worker : shop.workers)
    {
        if (worker.assignedClient != nullptr)
        {
            return worker.assignedClient;
        }
    }

    return nullptr;
}

void assign_workers(Shop& shop)
{
    for (auto& worker : shop.workers)
    {
        if (worker.assignedClient != nullptr)
        {
            continue;
        }

        Client* client{ find_assigned_client(shop) };

        if (client == nullptr)
        {
            client = take_first_waiting(shop);
        }

        worker.assignedClient = client;
    }
}

void cut_one_minute(MinutesLeft* minutes)
{
    assert(minutes != nullptr);
    assert(minutes->value > 0);

    *minutes = MinutesLeft{ minutes->value - 1 };
}

bool client_done(const Client& client)
{
    return client.hairCompletion.value == 0;
}

enum class TickResult
{
    Unassigned,
    StillWorking,
    Done,
};

TickResult tick_worker(Worker& worker)
{
    Client* client{ worker.assignedClient };

    if (client == nullptr)
    {
        return TickResult::Unassigned;
    }

    if (client->hairCompletion.value > 0)
    {
        cut_one_minute(&client->hairCompletion);
    }

    if (client_done(*client))
    {
        worker.assignedClient = nullptr;
        return TickResult::Done;
    }

    return TickResult::StillWorking;
}

void tick_all_workers(Shop& shop)
{
    for (auto& worker : shop.workers)
    {
        tick_worker(worker);
    }
}

bool has_waiting_clients(const Shop& shop)
{
    for (const auto& slot : shop.queue)
    {
        if (slot != nullptr)
        {
            return true;
        }
    }

    return false;
}

bool has_busy_workers(const Shop& shop)
{
    for (const auto& worker : shop.workers)
    {
        if (worker.assignedClient != nullptr)
        {
            return true;
        }
    }

    return false;
}

bool shop_done(const Shop& shop)
{
    return !has_waiting_clients(shop)
        && !has_busy_workers(shop);
}

int main()
{
    Client alice{
        .label = "alice",
        .hairCompletion = { 2 },
    };

    Client bob{
        .label = "bob",
        .hairCompletion = { 3 },
    };

    Client charlie{
        .label = "charlie",
        .hairCompletion = { 4 },
    };

    Shop shop{};

    assert(add_client(shop, &alice) == AddClientResult::Added);
    assert(add_client(shop, &bob) == AddClientResult::Added);
    assert(add_client(shop, &charlie) == AddClientResult::Added);

    while (!shop_done(shop))
    {
        assign_workers(shop);
        tick_all_workers(shop);
    }

    assert(client_done(alice));
    assert(client_done(bob));
    assert(client_done(charlie));
}