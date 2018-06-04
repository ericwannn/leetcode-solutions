class BubbleSort {
public:
    int* bubbleSort(int* A, int n) {
        // write code here
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
              if (A[j] > A[j+1])
                {
                    int tmp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = tmp;
                }
            }
        }
        return A;
    }
};