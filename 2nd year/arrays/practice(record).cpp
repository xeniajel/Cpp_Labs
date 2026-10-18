#include <iostream>
#include <array>

struct Recording
{
    std::array<double, 3> samples;
};

Recording NewRecording(Recording recordingsFirst, Recording recordingSecond)
{
    Recording result;
    result.samples[0] = 0.25 * recordingsFirst.samples[0] + 0.75 * recordingSecond.samples[0];
    result.samples[1] = 0.25 * recordingsFirst.samples[1] + 0.75 * recordingSecond.samples[1];
    result.samples[2] = 0.25 * recordingsFirst.samples[2] + 0.75 * recordingSecond.samples[2];

    return result;

}

int main()
{
    Recording first{{0.8, 0.4, -0.6}};
    Recording second{{0.4, -0.4, 0.8}};

    Recording result = NewRecording(first, second);

    std::cout << result.samples[0] << std::endl;
    std::cout << result.samples[1] << std::endl;
    std::cout << result.samples[2] << std::endl;

    return 0;
}