#include <iostream>

struct SourceCode{
    int strings;
};

struct MachineCode{
    int instructions;
};

struct LevelOfOptimisation
{
    int level;
};

struct Compilator
{
    double coeff[4];
    LevelOfOptimisation levelOfOptimisation;
};

double GetCoeff(Compilator compilator)
{
    return compilator.coeff[compilator.levelOfOptimisation.level];
}

MachineCode compile (SourceCode source, Compilator compilator)
{
    // source.strings * 3 / 10
    
    double res = static_cast<double>(source.strings) * GetCoeff(compilator);
    int resint = static_cast<int>(res); 
    return {resint};
}

int main()
{
    SourceCode source{50};

    Compilator compilator{
        { 1.0, 0.9, 0.5, 0.3 },
        { 2 }
    };

    MachineCode res = compile(source, compilator);

    double selectedCoeff = GetCoeff (compilator);

    std::cout << res.instructions << std::endl;
    std::cout << selectedCoeff << std::endl;
}