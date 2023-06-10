// allocation_tracking_basic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

struct AllocationMetrics {
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage() {
        return TotalAllocated - TotalFreed;
    }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size) {
    std::cout << "Allocating memory : " << size << std::endl;

    s_AllocationMetrics.TotalAllocated += size;

    return malloc(size);
}

void operator delete(void* memory, size_t size) {
    std::cout << "Freeing Up Memory : " << size << std::endl;

    s_AllocationMetrics.TotalFreed += size;
    
    free(memory);
}

static void PrintUsage() {
    std::cout << "Memory in Use : " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

struct Object {
    int x, y, z;
};

int main()
{
    PrintUsage();
    std::string str = "Chero";
    PrintUsage();
    {
        std::unique_ptr<Object> obj = std::make_unique<Object>();
        PrintUsage();
    }
    PrintUsage();
    

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
