#include "head.hpp"
#include "CIntN.hpp"
#include "CIntN0.hpp"

#include <random>


void MeasTime() {
    size_t SIZE ;
    size_t MAX_DIGITS;

    std::cout << "Input array size: ";
    std::cin >> SIZE;
    std::cout << "Input count of digits: ";
    std::cin >> MAX_DIGITS;
    
    std::vector<CIntN0> for_sum1;
    std::vector<CIntN0> for_sum2;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<> first_digit(1, 9); // диапазон для первой цифры
    std::uniform_int_distribution<> digit(0, 9); //остальные
    std::uniform_int_distribution<> d(1, MAX_DIGITS);//для ячейки
    
    for(size_t i = 0; i < SIZE; ++i) {
        size_t size1 = d(gen);
        std::string num1;
        size_t c = first_digit(gen);
        num1.push_back(static_cast<char>(c+48));
        for(size_t j = 1; j < size1; ++j) {
            c = digit(gen);
            num1.push_back(static_cast<char>(c+48));
        }
        
        size_t size2 = d(gen);
        std::string num2;
        c = first_digit(gen);
        num2.push_back(static_cast<char>(c+48));
        for(size_t j = 1; j < size2; ++j) {
            c = digit(gen);
            num2.push_back(static_cast<char>(c+48));
        }
        
        //std::cout << num1 << " " << num2 << "\n";
        for_sum1.push_back({static_cast<int>(size1), num1});
        for_sum2.push_back({static_cast<int>(size2), num2});
    }
    
    std::vector<CIntN0> sum(SIZE);
    
    auto start_time = std::chrono::steady_clock::now();
    
    for(size_t i = 0; i < SIZE; ++i) {
        sum[i] = for_sum1[i]+for_sum2[i];
    }
    
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    std::cout << "Time without parallel: " << elapsed_ns.count() << " ns\n";
    
    sum.clear();
    sum.resize(SIZE);
    
    start_time = std::chrono::steady_clock::now();
    
    #pragma omp parallel for
    for(size_t i = 0; i < SIZE; ++i) {
        sum[i] = for_sum1[i]+for_sum2[i];
    }
    
    end_time = std::chrono::steady_clock::now();
    elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    std::cout << "Time with parallel: " << elapsed_ns.count() << " ns\n";
    
}
