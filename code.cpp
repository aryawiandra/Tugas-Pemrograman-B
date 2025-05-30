#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

class DrugDosageCalculator {
private:
    // Parameter farmakokinetik
    double ke;          // Konstanta eliminasi (per jam)
    double Vd;          // Volume distribusi (L)
    double targetConc;  // Konsentrasi target (mg/L)
    double currentTime; // Waktu saat ini (jam)
    
    // Parameter Newton-Raphson
    double tolerance;
    int maxIterations;
    
public:
    DrugDosageCalculator() {
        tolerance = 1e-6;
        maxIterations = 100;
    }
    
    // Fungsi untuk membersihkan layar (cross-platform)
    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    
    // Fungsi untuk menampilkan header
    void displayHeader() {
        cout << "=========================================" << endl;
        cout << "   APLIKASI PERHITUNGAN DOSIS OBAT     " << endl;
        cout << "     Metode Newton-Raphson Method       " << endl;
        cout << "=========================================" << endl;
        cout << endl;
    }
    
    // Fungsi konsentrasi obat: C(t) = (D/Vd) * e^(-ke*t)
    // Kita ingin mencari D sehingga C(t) = target
    // Persamaan: (D/Vd) * e^(-ke*t) - target = 0
    double concentrationFunction(double dose) {
        return (dose / Vd) * exp(-ke * currentTime) - targetConc;
    }
    
    // Turunan fungsi terhadap dosis D: f'(D) = (1/Vd) * e^(-ke*t)
    double concentrationDerivative(double dose) {
        return (1.0 / Vd) * exp(-ke * currentTime);
    }
    
    // Implementasi Metode Newton-Raphson
    double newtonRaphson(double initialGuess) {
        double x = initialGuess;
        int iteration = 0;
        
        cout << "\n=== ITERASI NEWTON-RAPHSON ===" << endl;
        cout << "Iter\tX(n)\t\tF(X)\t\tF'(X)\t\tX(n+1)\t\tError" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        
        do {
            double fx = concentrationFunction(x);
            double fpx = concentrationDerivative(x);
            
            if (abs(fpx) < 1e-12) {
                cout << "Error: Turunan mendekati nol!" << endl;
                return -1;
            }
            
            double xNew = x - fx / fpx;
            double error = abs(xNew - x);
            
            cout << fixed << setprecision(6);
            cout << iteration + 1 << "\t" << x << "\t" << fx << "\t" 
                 << fpx << "\t" << xNew << "\t" << error << endl;
            
            if (error < tolerance) {
                cout << "\nKonvergensi tercapai!" << endl;
                return xNew;
            }
            
            x = xNew;
            iteration++;
            
        } while (iteration < maxIterations);
        
        cout << "Peringatan: Maksimum iterasi tercapai!" << endl;
        return x;
    }
    
    // Input parameter farmakokinetik
    void inputParameters() {
        clearScreen();
        displayHeader();
        
        cout << "=== INPUT PARAMETER FARMAKOKINETIK ===" << endl;
        cout << endl;
        
        cout << "Masukkan konstanta eliminasi (ke) [per jam]: ";
        cin >> ke;
        
        cout << "Masukkan volume distribusi (Vd) [Liter]: ";
        cin >> Vd;
        
        cout << "Masukkan konsentrasi target [mg/L]: ";
        cin >> targetConc;
        
        cout << "Masukkan waktu pemberian [jam]: ";
        cin >> currentTime;
        
        // Validasi input
        if (ke <= 0 || Vd <= 0 || targetConc <= 0 || currentTime < 0) {
            cout << "\nError: Semua parameter harus bernilai positif!" << endl;
            cout << "Tekan Enter untuk input ulang...";
            cin.ignore();
            cin.get();
            inputParameters();
        }
    }
    
    // Menampilkan hasil perhitungan
    void displayResults(double dose) {
        cout << "\n=== HASIL PERHITUNGAN ===" << endl;
        cout << "Dosis obat yang diperlukan: " << fixed << setprecision(2) 
             << dose << " mg" << endl;
        
        // Verifikasi hasil
        double actualConc = (dose / Vd) * exp(-ke * currentTime);
        cout << "Konsentrasi aktual yang dicapai: " << fixed << setprecision(4)
             << actualConc << " mg/L" << endl;
        cout << "Konsentrasi target: " << targetConc << " mg/L" << endl;
        cout << "Error: " << abs(actualConc - targetConc) << " mg/L" << endl;
        
        cout << "\n=== INTERPRETASI KLINIS ===" << endl;
        if (dose > 0 && dose < 10000) {
            cout << "Dosis dalam rentang yang wajar untuk kebanyakan obat." << endl;
        } else if (dose >= 10000) {
            cout << "Peringatan: Dosis sangat tinggi, periksa kembali parameter!" << endl;
        }
        
        cout << "\nCatatan: Hasil ini hanya untuk simulasi." << endl;
        cout << "Konsultasikan dengan tenaga medis untuk aplikasi klinis." << endl;
    }
    
    // Menu tentang aplikasi
    void aboutApplication() {
        clearScreen();
        displayHeader();
        
        cout << "=== TENTANG APLIKASI ===" << endl;
        cout << endl;
        cout << "Aplikasi ini menerapkan Metode Newton-Raphson untuk" << endl;
        cout << "menghitung dosis obat berdasarkan model farmakokinetik." << endl;
        cout << endl;
        cout << "MODEL YANG DIGUNAKAN:" << endl;
        cout << "C(t) = (D/Vd) * e^(-ke*t)" << endl;
        cout << endl;
        cout << "Dimana:" << endl;
        cout << "- C(t) = Konsentrasi obat pada waktu t" << endl;
        cout << "- D    = Dosis obat (yang dicari)" << endl;
        cout << "- Vd   = Volume distribusi" << endl;
        cout << "- ke   = Konstanta eliminasi" << endl;
        cout << "- t    = Waktu setelah pemberian" << endl;
        cout << endl;
        cout << "METODE NEWTON-RAPHSON:" << endl;
        cout << "X(n+1) = X(n) - f(X(n))/f'(X(n))" << endl;
        cout << endl;
        cout << "Aplikasi ini membantu menentukan dosis yang tepat" << endl;
        cout << "untuk mencapai konsentrasi obat yang diinginkan." << endl;
        
        cout << "\nTekan Enter untuk kembali ke menu utama...";
        cin.ignore();
        cin.get();
    }
    
    // Menu utama
    void mainMenu() {
        int choice;
        
        do {
            clearScreen();
            displayHeader();
            
            cout << "=== MENU UTAMA ===" << endl;
            cout << "1. Hitung Dosis Obat" << endl;
            cout << "2. Tentang Aplikasi" << endl;
            cout << "3. Keluar" << endl;
            cout << endl;
            cout << "Pilih menu (1-3): ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    calculateDosage();
                    break;
                case 2:
                    aboutApplication();
                    break;
                case 3:
                    clearScreen();
                    cout << "Terima kasih telah menggunakan aplikasi ini!" << endl;
                    cout << "Aplikasi dikembangkan menggunakan Metode Newton-Raphson." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid! Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
            }
        } while (choice != 3);
    }
    
    // Fungsi utama perhitungan dosis
    void calculateDosage() {
        inputParameters();
        
        clearScreen();
        displayHeader();
        
        cout << "=== PARAMETER YANG DIGUNAKAN ===" << endl;
        cout << "Konstanta eliminasi (ke): " << ke << " per jam" << endl;
        cout << "Volume distribusi (Vd): " << Vd << " Liter" << endl;
        cout << "Konsentrasi target: " << targetConc << " mg/L" << endl;
        cout << "Waktu pemberian: " << currentTime << " jam" << endl;
        cout << endl;
        
        // Tebakan awal dosis (berdasarkan perkiraan sederhana)
        double initialGuess = targetConc * Vd * exp(ke * currentTime);
        cout << "Tebakan awal dosis: " << fixed << setprecision(2) 
             << initialGuess << " mg" << endl;
        
        // Hitung menggunakan Newton-Raphson
        double result = newtonRaphson(initialGuess);
        
        if (result > 0) {
            displayResults(result);
        } else {
            cout << "Perhitungan gagal! Periksa parameter input." << endl;
        }
        
        cout << "\nTekan Enter untuk kembali ke menu utama...";
        cin.ignore();
        cin.get();
    }
};

int main() {
    DrugDosageCalculator app;
    app.mainMenu();
    
    return 0;
}
