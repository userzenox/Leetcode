#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to maintain the max heap property
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;            // Initialize largest as root
        int left = 2 * i + 1;       // left child = 2*i + 1
        int right = 2 * i + 2;      // right child = 2*i + 2

        // If left child is larger than root
        if (left < n && nums[left] > nums[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && nums[right] > nums[largest])
            largest = right;

        // If largest is not root
        if (largest != i) {
            swap(nums[i], nums[largest]);

            // Recursively heapify the affected sub-tree
            heapify(nums, n, largest);
        }
    }

    // Main function to perform heap sort
    void heapsort(vector<int>& nums) {
        int n = nums.size();

        // Build a max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // One by one extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            swap(nums[0], nums[i]);

            // call max heapify on the reduced heap
            heapify(nums, i, 0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums);
        return nums;
    }
};

int main() {
    vector<int> nums = {5, 3, 8, 4, 1, 9, 2};
    
    Solution obj;
    vector<int> sorted = obj.sortArray(nums);

    cout << "Sorted array: ";
    for (int num : sorted)
        cout << num << " ";
    cout << endl;

    return 0;
}
