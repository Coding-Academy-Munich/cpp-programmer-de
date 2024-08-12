// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Ausnahmebehandlung</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Ausnahmebehandlung.cpp -->
// <!-- slides/module_180_error_handling/topic_130_handling_exceptions.cpp -->

// %% [markdown]
//
// # Behandeln von Exceptions
//
// Wir haben die folgende Funktion zur Berechnung ganzzahliger Quadratwurzeln
// definiert, die einen `domain_error` auslöst, falls `n` keine Quadratzahl ist:

// %%
#include <stdexcept>

// %%
int int_sqrt(int n) {
    for (int m = 0; m <= n; ++m) {
        if (m * m == n) {
            return m;
        }
    }
    throw std::domain_error("not a square number");
}


// %% [markdown]
//
// Wir konnten diese Funktion dann so verwenden:

// %%
#include <iostream>

void print_int_sqrt_or_throw(int n) {
    int root{int_sqrt(n)};
    std::cout << "The root of " << n << " is " << root << ".\n";
}

// %%
print_int_sqrt_or_throw(9)

// %%
// print_int_sqrt_or_throw(8)


// %% [markdown]
//
// Wie schreiben wir damit eine `print_int_sqrt()`-Funktion, die keinen Fehler
// auslöst, wenn `n` keine Quadratzahl ist?

// %%
void print_int_sqrt(int n) {
    try {
        int root{int_sqrt(n)};
        std::cout << "The root of " << n << " is " << root << ".\n";
    } catch (std::domain_error& err) {
        std::cout << err.what() << "\n";
    }
}

// %%
print_int_sqrt(9)


// %%
print_int_sqrt(8)

// %% [markdown]
//
// ## Ausnahmebehandlung
//
// - Ausnahmen können mit einem `try`/`catch`-Block behandelt werden
// - Alle "passenden" Ausnahmen, die während der Ausführung des `try`-Blocks
//   ausgelöst werden, führen zur Ausführung des `catch`-Blocks
// - Wir sagen, die Ausnahme wurde behandelt
// - Nach der Behandlung der Ausnahme wird das Programm nach dem `try`/`catch`-Block
//   weiter ausgeführt

// %% [markdown]
//
// ## Workshop: Bank Account (Teil 2)
//
// Wir haben eine Klasse `BankAccount` definiert, die in folgenden Fällen einen
// `std::domain_error` auslöst:
//
// - Wenn ein neuer `BankAccount` mit negativer `balance` angelegt werden soll.
// - Wenn `deposit` mit einem negativen Wert aufgerufen wird.
// - Wenn `withdraw` mit einem negativen Wert aufgerufen wird oder durch das
//   Abheben des Betrags die `balance` des Kontos negativ werden würde.

// %% [markdown]
//
// Testen Sie die Funktionalität der Klasse sowohl für erfolgreiche
// Transaktionen, als auch für Transaktionen, die Exceptions auslösen.
// Behandeln Sie dabei die Ausnahmen, die ausgelöst werden und geben Sie
// eine sinnvolle Nachricht aus.

// %%
class BankAccount
{
public:
    BankAccount(double balance);

    void deposit(double amount);
    void withdraw(double amount);

    double balance() const;

private:
    double balance_;
}

// %%
BankAccount::BankAccount(double balance) : balance_(balance) {
    if (balance < 0) {
        throw std::domain_error(
            "Cannot create an account with negative balance.");
    }
}

// %%
void BankAccount::deposit(double amount) {
    if (amount < 0) {
        throw std::domain_error("Cannot deposit a negative amount.");
    }
    balance_ += amount;
}

// %%
void BankAccount::withdraw(double amount) {
    if (amount < 0) {
        throw std::domain_error("Cannot withdraw a negative amount.");
    }
    if (balance_ - amount < 0) {
        throw std::domain_error("Cannot withdraw more than the balance.");
    }
    balance_ -= amount;
}

// %%
double BankAccount::balance() const {
    return balance_;
}

// %%
try {
    BankAccount{-100.0};
} catch (std::domain_error& err) {
    std::cout << "ERROR: " << err.what() << "\n";
}

// %%
BankAccount b{100.0};
b.balance()

// %%
b.deposit(200.0);
b.balance()

// %%
try {
    b.deposit(-100.0);
} catch (std::domain_error& err) {
    std::cout << "ERROR: " << err.what() << "\n";
}
b.balance()

// %%
b.withdraw(50.0);
b.balance()

// %%
try {
    b.withdraw(-200.0);
} catch (std::domain_error& err) {
    std::cout << "ERROR: " << err.what() << "\n";
}
b.balance()

// %%
try {
    b.withdraw(1000.0);
} catch (std::domain_error& err) {
    std::cout << "ERROR: " << err.what() << "\n";
}
b.balance()

// %%
