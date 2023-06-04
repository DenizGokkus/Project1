#include "sequence.h"
#include <string>

//produce function

template <typename Key, typename Info>
Sequence<Key, Info> produce(const Sequence<Key, Info>& seq1, int start1, int length1, const Sequence<Key, Info>& seq2, int start2, int length2, int repeat) {

    // Make sure the result linked list is empty 
    Sequence<Key, Info> result;
    result.remove_all();

    // Check if any of the inputs except start and result is incorrect 
    if (length1 <= 0 || length2 <= 0 || repeat <= 0 || seq1.count_elements() <= 0 || seq2.count_elements() <= 0 ) {
        cout << "Invalid input" << endl;
        return result;
    }

    // Create copies of the input sequences
    Sequence<Key, Info> copySeq1(seq1);
    Sequence<Key, Info> copySeq2(seq2);

    // Remove `start1` number of elements from the beginning of `copySeq1`
    for (int j = 0; j < start1; j++) {
        copySeq1.remove_first();
    }
    // Remove `start2` number of elements from the beginning of `copySeq2`
    for (int j = 0; j < start2; j++) {
        copySeq2.remove_first();
    }

    for (int i = 0; i < repeat; i++) {
        // Insert `length1` number of elements from the beginning of `copySeq1` into the beginning of `result`
        for (int j = 0; j < length1; j++) {
            if (copySeq1.count_elements() == 0) {
                break;
            }
            result.insert_end(copySeq1.current_Key(), copySeq1.current_Info());
            copySeq1.remove_first();         
        }
        // Insert `length2` number of elements from the beginning of `copySeq2` into the end of `result`
        for (int n = 0; n < length2; n++) {
            if (copySeq2.count_elements() == 0) {
                break;
            }
            result.insert_end(copySeq2.current_Key(), copySeq2.current_Info());
            copySeq2.remove_first();
        }

        if (copySeq2.count_elements() == 0 && copySeq1.count_elements() == 0) {
            break;
        }
    }
    // Returns result list
    return result;
}
