void insertionSort(int arr[], int n) {
    int i, key, j; // 1 vez: c1
    for(i = 1; i < n; i++) { // (n - 1) vezes: c2 
        key = arr[i]; // (n - 1) vezes: c3
        j = i - 1; // (n - 1) vezes: c4
        while (j >= 0 && arr[j] > key) { // (n - 1) * (n + 1) vezes: c5
            arr[j + 1] = arr[j]; // (n + 1) vezes: c6
            j = j - 1; // (n + 1) vezes: c7
        }
        arr[j + 1] == key; // (n - 1) vezes: c8
    }
}