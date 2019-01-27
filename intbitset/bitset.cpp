#include <bitset>
#include <deque>
#include <cmath>

// preprocessor param can switch 32/64
typedef unsigned long long int word_t;
typedef std::bitset<64> word_bit_set_t;

class WordBitSet {
    public:
        size_t i;
        std::bitset<64> b;
        std::deque<word_bit_set_t> lb;

    private:
        word_t bit_size = 0;
        word_t bit_offset = 0;
        word_t words = 0;
        double resize_fold = 1.0;

    WordBitSet(unsigned int size) {
        lb.push_back(word_bit_set_t());
    }

    void add(word_t element) {
        word_t word_offset = get_word_offset(element);
        if (word_offset + 1 > words) {
            increase_size(element);
        }
        lb[word_offset].set(element % 64, true);
    }

    void increase_size(word_t new_bit_size) {
        long long increase = new_bit_size - bit_size;

        if (increase > 0) {
            increase *= ceil(resize_fold);
            words += ceil(increase / 64);
            lb.resize(words);
        }

    }


    word_t get_word_offset(word_t bit_offset) {
        return bit_offset / 64; // gets floored?
    }


};
