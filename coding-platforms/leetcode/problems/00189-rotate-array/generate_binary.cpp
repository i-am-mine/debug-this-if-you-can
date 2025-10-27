#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <cstdlib>

void write_binary_file(uint64_t n, uint64_t k, const std::string& file_path) {
    std::cout << "Creating binary file " << file_path
              << " with n=" << n << ", k=" << k << "...\n";

    std::ofstream fout(file_path, std::ios::binary);
    if (!fout) {
        std::cerr << "Cannot open file for writing: " << file_path << "\n";
        return;
    }

    fout.write(reinterpret_cast<const char*>(&n), sizeof(uint64_t));
    fout.write(reinterpret_cast<const char*>(&k), sizeof(uint64_t));

    // Original array
    for (uint32_t i = 1; i <= n; ++i) {
        fout.write(reinterpret_cast<const char*>(&i), sizeof(uint32_t));
    }

    // Rotated array
    for (uint32_t i = n - k; i < n; ++i) {
        uint32_t val = i + 1;
        fout.write(reinterpret_cast<const char*>(&val), sizeof(uint32_t));
    }
    for (uint32_t i = 0; i < n - k; ++i) {
        uint32_t val = i + 1;
        fout.write(reinterpret_cast<const char*>(&val), sizeof(uint32_t));
    }

    fout.close();
    std::cout << "Finished writing " << file_path << "\n";
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " n k filename\n";
        return 1;
    }

    uint64_t n = std::stoull(argv[1]);
    uint64_t k = std::stoull(argv[2]);
    std::string filename = argv[3];

    write_binary_file(n, k, filename);
    return 0;
}
