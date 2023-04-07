#include <iostream>
#include <cmath>

// Fonksiyon: enYakinKomsu
// Açýklama: Verilen bir veri setinde, belirli bir veri örneðine en yakýn komþuyu bulur.
// Parametreler:
//     data: veri seti (her bir satýr bir veri örneði içerir)
//     query: bulunacak olan veri örneði
//     numFeatures: veri özelliklerinin sayýsý
//     numExamples: veri örneklerinin sayýsý
// Dönüþ: En yakýn komþunun veri setindeki indeksi
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
    // Örnek bir veri seti
    double data[][3] = {
        {1.2, 3.4, 5.6},
        {7.8, 9.0, 1.2},
        {3.4, 5.6, 7.8},
        {9.0, 1.2, 3.4},
    };

    // Örnek bir veri örneði
    double query[] = {4.5, 6.7, 8.9};

    // En yakýn komþuyu bul
    int closestIndex = enYakinKomsu((double**)data, query, 3, 4);

    // Sonucu yazdýr
    std::cout << "En yakin komsu indeksi: " << closestIndex << std::endl;

    return 0;
}

