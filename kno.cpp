#include <iostream>
#include <cmath>

// Fonksiyon: enYakinKomsu
// A��klama: Verilen bir veri setinde, belirli bir veri �rne�ine en yak�n kom�uyu bulur.
// Parametreler:
//     data: veri seti (her bir sat�r bir veri �rne�i i�erir)
//     query: bulunacak olan veri �rne�i
//     numFeatures: veri �zelliklerinin say�s�
//     numExamples: veri �rneklerinin say�s�
// D�n��: En yak�n kom�unun veri setindeki indeksi
int enYakinKomsu(double** data, double* query, int numFeatures, int numExamples) {
    int closestIndex = 0;
    double closestDist = INFINITY;

    for (int i = 0; i < numExamples; i++) {
        double dist = 0;
        for (int j = 0; j < numFeatures; j++) {
            double diff = data[i][j] - query[j];
            dist += diff * diff;
        }
        dist = sqrt(dist);
        if (dist < closestDist) {
            closestDist = dist;
            closestIndex = i;
        }
    }

    return closestIndex;
}

int main() {
    // �rnek bir veri seti
    double data[][3] = {
        {1.2, 3.4, 5.6},
        {7.8, 9.0, 1.2},
        {3.4, 5.6, 7.8},
        {9.0, 1.2, 3.4},
    };

    // �rnek bir veri �rne�i
    double query[] = {4.5, 6.7, 8.9};

    // En yak�n kom�uyu bul
    int closestIndex = enYakinKomsu((double**)data, query, 3, 4);

    // Sonucu yazd�r
    std::cout << "En yakin komsu indeksi: " << closestIndex << std::endl;

    return 0;
}

