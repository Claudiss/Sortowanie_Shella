// Sortowanie_Shella.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>//Bibloteka z szablonem tablicy(kontera) dynamicznego, aby ciąg podziałów łatwo stworzyć
#include <cmath>//Do funkcji podłoga
#include <algorithm>//Bibloteka do funkcji reverse
#include <cstdlib>//Bibloteka do liczb psełdolosowych
#include <chrono>//Bibloteka do mierzenia czasu
#include <fstream>//Bibloteka do zpisu danych do pliku


std::chrono::steady_clock::time_point start;//Ustawienie zmeinnych globalnych pozwala nam, na mierzenie czasu wykonywania algorytmu, z pominięciem czsau na stworzenie ciągu podziałów
std::chrono::steady_clock::time_point end;

//Sortowanie Shella z krokiem n^k ma nazwę funkcji ShellSortk
// 
// 
// 
//void ShellSort(int* tab, int n) {
//    int przerwa = n / 2;
//    while (przerwa >= 1) {
//        for (int i = przerwa; i < n; i += 1) {
//            int temp = tab[i];
//            int j;
//            for (j = i; j >= przerwa && tab[j - przerwa] > temp; j -= przerwa)
//                tab[j] = tab[j - przerwa];
//            tab[j] = temp;
//        }
//        przerwa /= 2;
//    }
//}  //Modelowa funkcja

//Sortowanie Shella z krokiem n^k ma nazwę funkcji ShellSortk

void ShellSort2(std::vector<int>& t, int n) {
    //n-rozmiar sortowanej tablicy
    

    //Zaczijmy od przypadku n^2. Podział zawsze kończy się 1
    std::vector<int> gaps;
    for (int i = 1; i<n; i++) {
        int h = floor(n / pow(2, i));
        if (h <= 1) {
            gaps.push_back(1);
            break;
        }
        gaps.push_back(h);


    }

    
    //Mamy tabelę podziałów od największego, do 1. Teraz odwórćmy tą tabele, abysmy mieli od 1 do największego
    std::reverse(gaps.begin(), gaps.end());


    //Rozpoczęcie mierzenia czasu
    start = std::chrono::steady_clock::now();
    for (int gap = gaps.size() - 1; gap >= 0; gap--) {//Pętla wybiera kolejne podziały
        for (int i = gaps[gap]; i < n; i++) {
            int temp = t[i];//Przypisanie czasowe, aby miec pewność, że i-ta pozycja zostanie przechowana
            int j = i;
            while ((j >= gaps[gap]) && (t[j - gaps[gap]] > temp))
            {
                    t[j] = t[j - gaps[gap]];
                    j -= gaps[gap];
            }
            t[j] = temp;
        }
    }
    //Zakończenie mierzenia czasu:
    end = std::chrono::steady_clock::now();
    //auto working_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    //auto working_time_nanosecond = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    

}

void ShellSort3_2(std::vector<int>& t, int n) {
    //n-rozmiar sortowanej tablicy
    //Złożoność obliczeniowa O(n^3/2)
    //Ciąg: Frank, Lazarus, 1960

    // Podział zawsze kończy się 1
    std::vector<int> gaps;
    for (int i = 1; i < n; i++) {
        int h = 2* floor(n / pow(2, i+1))+1;
        if (h <= 1) {
            gaps.push_back(1);
            break;
        }
        gaps.push_back(h);
    }
    //Mamy tabelę podziałów od największego, do 1. Teraz odwórćmy tą tabele, abysmy mieli od 1 do największego
    std::reverse(gaps.begin(), gaps.end());
    start = std::chrono::steady_clock::now();


    for (int gap = gaps.size() - 1; gap >= 0; gap--) {//Pętla wybiera kolejne podziały
        for (int i = gaps[gap]; i < n; i++) {
            int temp = t[i];//Przypisanie czasowe, aby miec pewność, że i-ta pozycja zostanie przechowana
            int j = i;
            while ((j >= gaps[gap]) && (t[j - gaps[gap]] > temp))
            {
                t[j] = t[j - gaps[gap]];
                j -= gaps[gap];
            }
            t[j] = temp;
        }

    }
    end = std::chrono::steady_clock::now();


}

void ShellSort4_3(std::vector<int>& t, int n) {
    //n-rozmiar sortowanej tablicy
    //Złożoność obliczeniowa O(n^4/3)
    //Ciąg:Sedgewick, 1986

    // Podział zawsze kończy się 1
    std::vector<int> gaps;
    gaps.push_back(1);
    for (int i = 1; i < n; i++) {
        int h = pow(4,i)+3*pow(2,i-1)+1;
        if (h > n) {
            
            break;
        }
        gaps.push_back(h);
    }
    //Mamy tabelę podziałów od największego, do 1. Teraz odwórćmy tą tabele, abysmy mieli od 1 do największego
    std::reverse(gaps.begin(), gaps.end());


    start = std::chrono::steady_clock::now();
    for (int gap = gaps.size() - 1; gap >= 0; gap--) {//Pętla wybiera kolejne podziały
        for (int i = gaps[gap]; i < n; i++) {
            int temp = t[i];//Przypisanie czasowe, aby miec pewność, że i-ta pozycja zostanie przechowana
            int j = i;
            while ((j >= gaps[gap]) && (t[j - gaps[gap]] > temp))
            {
                t[j] = t[j - gaps[gap]];
                j -= gaps[gap];
            }
            t[j] = temp;
        }

    }
    end = std::chrono::steady_clock::now();
}


void ExtraShellSort3_2(std::vector<int>& t, int n) {
    //n-rozmiar sortowanej tablicy
    //Złożoność obliczeniowa O(n^3/2)
    //Ciąg:Papernov & Stasevich, 1965

    // Podział zawsze kończy się 1
    std::vector<int> gaps;
    gaps.push_back(1);
    for (int i = 1; i < n; i++) {
        int h = pow(2,i) + 1;
        if (h > n) {

            break;
        }
        gaps.push_back(h);
    }
    //Mamy tabelę podziałów od największego, do 1. Teraz odwórćmy tą tabele, abysmy mieli od 1 do największego
    std::reverse(gaps.begin(), gaps.end());


    start = std::chrono::steady_clock::now();
    for (int gap = gaps.size() - 1; gap >= 0; gap--) {//Pętla wybiera kolejne podziały
        for (int i = gaps[gap]; i < n; i++) {
            int temp = t[i];//Przypisanie czasowe, aby miec pewność, że i-ta pozycja zostanie przechowana
            int j = i;
            while ((j >= gaps[gap]) && (t[j - gaps[gap]] > temp))
            {
                t[j] = t[j - gaps[gap]];
                j -= gaps[gap];
            }
            t[j] = temp;
        }

    }
    end = std::chrono::steady_clock::now();


}

void ExtraShellSort3_2_KunthPraat(std::vector<int>& t, int n) {
    //n-rozmiar sortowanej tablicy
    //Złożoność obliczeniowa O(n^3/2)
    //Ciąg:Knuth, 1973,[3] based on Pratt, 1971

    // Podział zawsze kończy się 1
    std::vector<int> gaps;
    gaps.push_back(1);
    for (int i = 1; i < n; i++) {
        int h = (pow(3, i) - 1)/2;
        if (h >floor(n/3)+1) {

            break;
        }
        gaps.push_back(h);
    }
    //Mamy tabelę podziałów od największego, do 1. Teraz odwórćmy tą tabele, abysmy mieli od 1 do największego
    std::reverse(gaps.begin(), gaps.end());


    start = std::chrono::steady_clock::now();
    for (int gap = gaps.size() - 1; gap >= 0; gap--) {//Pętla wybiera kolejne podziały
        for (int i = gaps[gap]; i < n; i++) {
            int temp = t[i];//Przypisanie czasowe, aby miec pewność, że i-ta pozycja zostanie przechowana
            int j = i;
            while ((j >= gaps[gap]) && (t[j - gaps[gap]] > temp))
            {
                t[j] = t[j - gaps[gap]];
                j -= gaps[gap];
            }
            t[j] = temp;
        }

    }
    end = std::chrono::steady_clock::now();


}

void ExtraShellSortUnknow(std::vector<int>& t, int n) {
    //n-rozmiar sortowanej tablicy
    //Złożoność obliczeniowa [nieznana](twają wyznaczenia eksperymentalne
    //Ciąg:Ciura, 2001

    // Podział zawsze kończy się 1
    std::vector<int> gaps;
    gaps.push_back(701);
    gaps.push_back(301);
    gaps.push_back(132);
    gaps.push_back(57);
    gaps.push_back(23);
    gaps.push_back(10);
    gaps.push_back(4);
    gaps.push_back(1);
    
    


    start = std::chrono::steady_clock::now();
    for (int gap = gaps.size() - 1; gap >= 0; gap--) {//Pętla wybiera kolejne podziały
        for (int i = gaps[gap]; i < n; i++) {
            int temp = t[i];//Przypisanie czasowe, aby miec pewność, że i-ta pozycja zostanie przechowana
            int j = i;
            while ((j >= gaps[gap]) && (t[j - gaps[gap]] > temp))
            {
                t[j] = t[j - gaps[gap]];
                j -= gaps[gap];
            }
            t[j] = temp;
        }

    }
    end = std::chrono::steady_clock::now();


}







bool ChechSort(std::vector<int>& t,int n) {
    //Funkcja sprawdza, czy tablica została posortowana
    for (int i = 0; i < n-1; i++) {
        if (t[i] > t[i + 1]) {
            return false;
        }
    }
    return true;
}


void PrintTab(std::vector<int>& t, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << t[i] << ' ';
    }
}


int main()
{
    std::cout << "Program do testowania algorytmu SellSort\n";
    std::vector<int> tabica;
    tabica.push_back( 9);
    tabica.push_back(5);
    tabica.push_back( 7);
    tabica.push_back( 3);
    tabica.push_back( 1);
    tabica.push_back( 4);
    tabica.push_back( 2);
    tabica.push_back( 8);
    tabica.push_back( 6);
    tabica.push_back( 0);
    ShellSort4_3(tabica, 10);
    std::cout << "Tablica zostala posortowana : " << ChechSort(tabica, 10)<<"\n";

    //std::vector<int> table;
    //table[0] = 4;
    //table[1] = 2;
    //table[2] = 3;
    //table[3] = 0;
    //ShellSort2(table, 4);
    
    srand(time(NULL));

    std::vector<int> tablica;//Tablica do złożoności n^2(Shell)
    std::vector<int> tablica2;//Tablica do złożoności n^3/2(Frank, Lazarus)
    std::vector<int> tablica3;//Tablica do złożoności n^4/3(Sedewick 4^k+3*2^(k-1)+1)

    std::vector<int> tablica_extra;//Tablica do złożoności n^3/2(Paperov)
    std::vector<int> tablica2_extra;//Tablica do złożoności n^3/2(Knut)
    std::vector<int> tablica3_extra;//Tablica do złożoności nn(Ciura)
    


    //Plik z danymi wyjściowymi:
    std::ofstream file;
    file.open("Dane.csv");

    file << "Rozmiar tablicy, Shell(n^2),Frank-Lazarus(n^3/2),Sedgewick(n^4/3)[ten prostrzy],Papernov & Stasevich(n^3/2),Knuth 1973 based on Pratt(n^3/2),Ciura(nieznane)\n";


    //auto start = std::chrono::steady_clock::now();
    //auto end = std::chrono::steady_clock::now();
    auto working_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    auto working_time_nanosecond = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    //Pętla generująca lowowe tablice i ogarniająca sortowanie
    for (int i = 10000; i <= 500000; i += 10000) {
        for (int j = 0; j < i; j++) {
            tablica.push_back( (std::rand() % i) + 0);
            tablica2.push_back((std::rand() % i) + 0);
            tablica3.push_back((std::rand() % i) + 0);

            tablica_extra.push_back((std::rand() % i) + 0);
            tablica2_extra.push_back((std::rand() % i) + 0);
            tablica3_extra.push_back((std::rand() % i) + 0);
        }
        file << i << ",";
        //start = std::chrono::steady_clock::now();
        ShellSort2(tablica, i);
       // end = std::chrono::steady_clock::now();
        working_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        working_time_nanosecond = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        if (ChechSort(tablica, i)) {
            std::cout << "tablica o wymiarze:" << i << " zostala posortowana.\n";
            file << working_time.count()<<",";
        }
        else
        {
            std::cout << "tablica o wymiarze:" << i << " nie zostala posortowana.\n";
        }
        //start = std::chrono::steady_clock::now();
        ShellSort3_2(tablica2, i);
        //end = std::chrono::steady_clock::now();
        working_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        working_time_nanosecond = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        if (!ChechSort(tablica2, i)) {
            std::cout << "tablica2 o wymiarze:" << i << " nie zostala posortowana.\n";
        }
        else {
            file << working_time.count() << ",";
        }

        //start = std::chrono::steady_clock::now();
        ShellSort4_3(tablica3, i);
        //end = std::chrono::steady_clock::now();
        working_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        working_time_nanosecond = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        if (!ChechSort(tablica3, i)) {
            std::cout << "tablica3 o wymiarze:" << i << " nie zostala posortowana.\n";
        }
        else
        {
            file << working_time.count() << ",";
        }

        //Teraz te 3 dodatkowe


        ExtraShellSort3_2(tablica_extra, i);
        working_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        working_time_nanosecond = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        if (ChechSort(tablica_extra, i)) {
            file << working_time.count() << ",";
        }
        else
        {
            std::cout << "Nieposortowano tablicy tablica_extra w iteracji :" << i;
        }


        ExtraShellSort3_2_KunthPraat(tablica2_extra, i);
        working_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        working_time_nanosecond = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        if (ChechSort(tablica2_extra, i)) {
            file << working_time.count() << ",";
        }
        else
        {
            std::cout << "Nieposortowano tablicy tablica2_extra w iteracji :" << i;
        }
        ExtraShellSortUnknow(tablica3_extra, i);
        working_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        working_time_nanosecond = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        if (ChechSort(tablica3_extra, i)) {
            file << working_time.count();
        }
        else
        {
            std::cout << "Nieposortowano tablicy tablica_extra w iteracji :" << i;
        }


        file << "\n";

        //Po zakończeniu po prostu czyszczę tablicę
        tablica.clear();
        tablica2.clear();
        tablica3.clear();
        tablica_extra.clear();
        tablica2_extra.clear();
        tablica3_extra.clear();

    }
    
    file.close();

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
