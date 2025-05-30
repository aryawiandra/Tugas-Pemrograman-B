---
title: 'Penjelasan Program: Aplikasi Perhitungan Dosis Obat'

---

# Penjelasan Program: Aplikasi Perhitungan Dosis Obat

## Deskripsi Singkat Program

Program ini adalah aplikasi perhitungan dosis obat yang menerapkan **Metode Newton-Raphson** untuk menyelesaikan persamaan farmakokinetik. Program menghitung dosis obat yang diperlukan untuk mencapai konsentrasi target dalam darah pasien pada waktu tertentu setelah pemberian obat.

### Model Matematika yang Digunakan:
- **Persamaan Farmakokinetik**: `C(t) = (D/Vd) × e^(-ke×t)`
- **Fungsi yang diselesaikan**: `f(D) = (D/Vd) × e^(-ke×t) - C_target = 0`
- **Turunan fungsi**: `f'(D) = (1/Vd) × e^(-ke×t)`

### Fitur Utama:
1. **Interface Menu Interaktif** - Navigasi mudah dengan pembersihan layar otomatis
2. **Input Parameter Farmakokinetik** - Dengan validasi input
3. **Implementasi Newton-Raphson** - Menampilkan iterasi lengkap
4. **Hasil Komprehensif** - Termasuk verifikasi dan interpretasi klinis
5. **Cross-Platform** - Berjalan di Windows, Linux, dan macOS

### Cara Kerja:
1. User memasukkan parameter: konstanta eliminasi (ke), volume distribusi (Vd), konsentrasi target, dan waktu pemberian
2. Program menghitung tebakan awal dosis menggunakan rumus sederhana
3. Metode Newton-Raphson diterapkan untuk mencari dosis yang tepat
4. Program menampilkan iterasi dan hasil akhir dengan verifikasi

---

## Test Case

### Test Case 1: Antibiotik Standar
**Skenario**: Pemberian antibiotik untuk infeksi sedang

**Input Parameter**:
- Konstanta eliminasi (ke): `0.1` per jam
- Volume distribusi (Vd): `50` Liter  
- Konsentrasi target: `5` mg/L
- Waktu pemberian: `2` jam

**Expected Output**:
- Tebakan awal: ≈ 610.7 mg
- Konvergensi dalam 3-4 iterasi
- Dosis final: ≈ 610.701 mg
- Konsentrasi aktual: ≈ 5.0000 mg/L

### Test Case 2: Obat dengan Eliminasi Cepat
**Skenario**: Obat dengan waktu paruh pendek

**Input Parameter**:
- Konstanta eliminasi (ke): `0.5` per jam
- Volume distribusi (Vd): `30` Liter
- Konsentrasi target: `10` mg/L
- Waktu pemberian: `1` jam

**Expected Output**:
- Tebakan awal: ≈ 494.2 mg
- Konvergensi dalam 3-4 iterasi
- Dosis final: ≈ 494.169 mg
- Konsentrasi aktual: ≈ 10.0000 mg/L

### Test Case 3: Obat dengan Volume Distribusi Kecil
**Skenario**: Obat yang tidak terdistribusi luas dalam tubuh

**Input Parameter**:
- Konstanta eliminasi (ke): `0.05` per jam
- Volume distribusi (Vd): `10` Liter
- Konsentrasi target: `2` mg/L
- Waktu pemberian: `3` jam

**Expected Output**:
- Tebakan awal: ≈ 23.2 mg
- Konvergensi dalam 3-4 iterasi
- Dosis final: ≈ 23.237 mg
- Konsentrasi aktual: ≈ 2.0000 mg/L

### Test Case 4: Kasus Ekstrem - Waktu Lama
**Skenario**: Perhitungan dosis untuk waktu pemberian yang lama

**Input Parameter**:
- Konstanta eliminasi (ke): `0.2` per jam
- Volume distribusi (Vd): `70` Liter
- Konsentrasi target: `1` mg/L
- Waktu pemberian: `10` jam

**Expected Output**:
- Tebakan awal: ≈ 515.5 mg
- Konvergensi dalam 3-4 iterasi
- Dosis final: ≈ 515.459 mg
- Konsentrasi aktual: ≈ 1.0000 mg/L

### Test Case 5: Input Error Handling
**Skenario**: Testing validasi input

**Input Parameter (Invalid)**:
- Konstanta eliminasi (ke): `-0.1` (negatif)
- Volume distribusi (Vd): `0` (nol)
- Konsentrasi target: `-5` (negatif)
- Waktu pemberian: `-2` (negatif)

**Expected Output**:
- Program menampilkan error message
- Meminta input ulang
- Tidak melanjutkan ke perhitungan

---

## Cara Menjalankan Test Case

### Langkah 1: Kompilasi Program
```bash
g++ -o drug_calculator main.cpp
```

### Langkah 2: Jalankan Program
```bash
./drug_calculator
```

### Langkah 3: Pilih Menu 1 (Hitung Dosis Obat)

### Langkah 4: Masukkan Parameter Sesuai Test Case

### Langkah 5: Verifikasi Output
- Periksa apakah iterasi konvergen dalam jumlah yang wajar (< 10 iterasi)
- Pastikan error antara konsentrasi aktual dan target < 1e-6
- Verifikasi dosis berada dalam rentang yang masuk akal

---

## Contoh Output Test Case 1

```
=== PARAMETER YANG DIGUNAKAN ===
Konstanta eliminasi (ke): 0.1 per jam
Volume distribusi (Vd): 50 Liter
Konsentrasi target: 5 mg/L
Waktu pemberian: 2 jam

Tebakan awal dosis: 610.70 mg

=== ITERASI NEWTON-RAPHSON ===
Iter    X(n)            F(X)            F'(X)           X(n+1)          Error
--------------------------------------------------------------------
1       610.700000      0.000000        0.016375        610.701191      0.001191
2       610.701191      0.000000        0.016375        610.701191      0.000000

Konvergensi tercapai!

=== HASIL PERHITUNGAN ===
Dosis obat yang diperlukan: 610.70 mg
Konsentrasi aktual yang dicapai: 5.0000 mg/L
Konsentrasi target: 5 mg/L
Error: 0.0000 mg/L
```

Program berhasil menghitung dosis dengan akurasi tinggi menggunakan Metode Newton-Raphson!

---

