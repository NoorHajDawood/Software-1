#include <stdio.h>
#include <string.h>

struct Date
{
    int day, month, year;
};

struct Transaction
{
    struct Date date;
    float amount;
    char info[40];
};

struct BankAccount
{
    int clientID;
    int accountID;
    float balance;
    int transactionCount;
    struct Transaction transactions[1000];
};

struct BankClient
{
    char firstName[20], lastName[20];
    int id;
    int accountCount;
};

struct Bank
{
    int clientCount;
    struct BankClient bankClients[100];
    int accountIndex;
    struct BankAccount bankAccounts[250];
} bank = {0}; // initializing bank here since we didn't learn how to allocate memory for pointers, and bank is too big to initialize it in main

void addBankClient(struct Bank *bank);             // adding a new Client to the bank
void createBankAccount(struct Bank *bank);         // creating a new account for a Client in the bank
void deposit_withdraw(struct Bank *bank, int mod); // depositing/withdrawing money to/from an account in the bank
void printClientList(struct Bank *bank);           // printing all Clients and their accounts in the bank
void printAccountTransactions(struct Bank *bank);  // printing all transactions from date to date of an account from the bank

int main(int argc, char const *argv[])
{
    // copied and edited a terminal menu from lecture
    int selection;
    char c;
    while (1)
    {
        printf("\n\t\tMenu\n");
        printf("1 - Add Client\t\t4 - Creat An Account\n2 - Deposit\t\t5 - Withdrawal\n3 - Print Clients\t6 - Print Transactions\n");
        printf("\t     7 - End\n\nSelect==>");
        scanf("%d", &selection);
        c = getchar();
        switch (selection)
        {
        case 1:
            addBankClient(&bank);
            break;
        case 2:
            deposit_withdraw(&bank, 1);
            break;
        case 3:
            printClientList(&bank);
            break;
        case 4:
            createBankAccount(&bank);
            break;
        case 5:
            deposit_withdraw(&bank, -1);
            break;
        case 6:
            printAccountTransactions(&bank);
            break;
        case 7:
            return 0;
        }
    }
    return 0;
}

void addBankClient(struct Bank *bank) // adding a new Client to the bank
{
    printf("Enter new client's information:\n");
    int id;
    do // ask for a uniqe client ID, have option to exit to main if -1 was the input
    {
        printf("\tID number> ");
        scanf("%d", &id);
        getchar();
        if (id == -1)
            return;
        for (int i = 0; i < bank->clientCount; i++)
            if (bank->bankClients[i].id == id)
            {
                printf("Client ID number already exists, please try again(-1 to return)\n");
                continue;
            }
        break;
    } while (1);

    struct BankClient *client = bank->bankClients + bank->clientCount; // inserting values to a client
    bank->clientCount++;
    client->id = id;
    printf("\tFirst Name> ");
    gets(client->firstName);
    printf("\tLast Name> ");
    gets(client->lastName);
}

struct BankClient *findClient(struct Bank *bank) // returning client by id if exists
{
    int id;
    struct BankClient *client = NULL;
    do // find a client with an id , or input -1 to exit to main
    {
        printf("Enter Client's ID number> ");
        scanf("%d", &id);
        if (id == -1)
            return NULL;
        for (int i = 0; i < bank->clientCount; i++)
            if (bank->bankClients[i].id == id)
                client = bank->bankClients + i;
        if (client == NULL)
            printf("ID number doesn't exist, please try again(-1 to return)\n");
    } while (client == NULL);
    return client;
}

void createBankAccount(struct Bank *bank) // creating a new account for a Client in the bank
{
    struct BankClient *client = findClient(bank);
    if (client == NULL)
        return;
    // linking an account to the client
    struct BankAccount *account = bank->bankAccounts + bank->accountIndex;
    account->clientID = client->id;
    account->accountID = bank->accountIndex;
    bank->accountIndex++;
    client->accountCount++;
    account->balance = 0.0F;
}
void showAccountsForClient(struct Bank *bank, struct BankClient *client) // printing out all of the client's accounts
{
    printf("\tClient's Accounts:\n");
    for (int i = 0; i < bank->accountIndex; i++)
    {
        if (bank->bankAccounts[i].clientID == client->id)
            printf("\t\tAccount Number: %d\t-\tBalance: %0.2f\n", i, bank->bankAccounts[i].balance);
    }
}
struct BankAccount *findAccount(struct Bank *bank, struct BankClient *client) // returning an account by id for a given client if exists
{
    showAccountsForClient(bank, client);
    int id;
    struct BankAccount *account = NULL;
    printf("Enter desired account's number> ");
    do // checking if account belongs to the client, -1 exits to main
    {
        scanf("%d", &id);
        if (id == -1)
            return NULL;
        if (id >= 0 && id < 250 && bank->bankAccounts[id].clientID == client->id)
            account = bank->bankAccounts + id;
        if (account == NULL)
            printf("wrong number, please try again(-1 to return)> ");
    } while (account == NULL);
    return account;
}
int isValidDate(int day, int month, int year) // checking if the date is legit
{
    if (year < 0)
        return 0;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day > 31 || day < 1)
            return 0;
        break;
    case 2:
        if (day > 28 || day < 1)
        {
            if (day == 29 && year % 4 == 0)
            {
                return 1;
            }
            return 0;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day > 30 || day < 1)
        {
            return 0;
        }
        break;
    default:
        return 0;
        break;
    }
    return 1;
}
int getDate(struct Date *date) // getting date from input
{
    do // make sure to get a legit date
    {
        scanf("%d/%d/%d", &date->day, &date->month, &date->year);
        if (isValidDate(date->day, date->month, date->year) == 0)
        {
            printf("Invalid Date, please try again (DD/MM/YYYY)>");
            continue;
        }
        break;
    } while (1);
}

int compareDate(struct Date *date1, struct Date *date2) // comparing 2 dates, return -1 if first is smaller, 0 if equal, 1 if first is larger
{
    if (date1->year > date2->year)
        return 1;
    if (date1->year < date2->year)
        return -1;
    if (date1->month > date2->month)
        return 1;
    if (date1->month < date2->month)
        return -1;
    if (date1->day > date2->day)
        return 1;
    if (date1->day < date2->day)
        return -1;
    return 0;
}

void increaseDate(struct Date *date) // increase date by 1 day
{
    switch (date->month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (date->day == 31)
        {
            date->day = 1;
            if (date->month == 12)
            {
                date->month = 0;
                date->year++;
            }
            date->month++;
        }
        else
            date->day++;
        break;
    case 2:
        if (date->day >= 28)
            if (date->day == 28 && date->year % 4 == 0)
            {
                date->day++;
            }
            else
            {
                date->day = 1;
                date->month++;
            }
        else
        {
            date->day++;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (date->day == 30)
        {
            date->day = 1;
            date->month++;
        }
        else
            date->day++;
        break;
    }
}

void deposit_withdraw(struct Bank *bank, int mod) // depositing/withdrawing money to/from an account in the bank
{
    struct BankClient *client = findClient(bank);
    if (client == NULL)
        return;
    if (client->accountCount == 0)
    {
        printf("Client has no accounts\n");
        return;
    }
    struct BankAccount *account = findAccount(bank, client);
    if (account == NULL)
        return;
    // getting the transaction's info
    struct Transaction *transaction = account->transactions + account->transactionCount;
    account->transactionCount++;
    printf("Transaction's amount> ");
    scanf("%f", &transaction->amount);
    getchar();
    printf("Transaction's information> ");
    gets(transaction->info);
    printf("transaction's date (DD/MM/YYYY)> ");
    getDate(&transaction->date);
    transaction->amount *= mod;
    account->balance += transaction->amount; // updating the account's balance
}

void printClientList(struct Bank *bank) // printing all Clients and their accounts in the bank
{
    for (int i = 0; i < bank->clientCount; i++)
    {
        printf("Name: %s %s\t\tID: %d\n", bank->bankClients[i].firstName, bank->bankClients[i].lastName, bank->bankClients[i].id);
        for (int j = 0; j < bank->bankClients[i].accountCount; j++)
        {
            showAccountsForClient(bank, bank->bankClients + i);
        }
    }
}

void printAccountTransactions(struct Bank *bank) // printing all transactions from date to date of an account from the bank
{
    struct BankClient *client = findClient(bank);
    if (client == NULL)
        return;
    if (client->accountCount == 0)
    {
        printf("Client has no accounts\n");
        return;
    }
    struct BankAccount *account = findAccount(bank, client);
    if (account == NULL)
        return;
    struct Date fromDate = {0}, toDate = {0};
    do // make sure that from date is smaller or equals to To date
    {
        printf("Please enter From Date (DD/MM/YYYY)> ");
        getDate(&fromDate);
        printf("Please enter To Date (DD/MM/YYYY)> ");
        getDate(&toDate);
        if (compareDate(&fromDate, &toDate) <= 0)
            break;
        printf("From Date must be smaller of equal to To Date\n");
    } while (1);
    printf("\n\t\t\t\tClient ID: %d\tAccount Number: %d\n\n", client->id, account->accountID);
    // getting balance since From Date
    float sum = 0.0F;
    for (int i = 0; i < account->transactionCount; i++)
    {
        if (compareDate(&account->transactions[i].date, &fromDate) < 0)
            sum += account->transactions[i].amount;
    }
    // printing all the transactions day by day
    printf("Date\t\t\t\t Amount\t\t\t\t\t\t     Information\t\t\t    Balance\n");
    for (struct Date date = fromDate; compareDate(&date, &toDate) <= 0; increaseDate(&date))
    {

        for (int i = 0; i < account->transactionCount; i++)
        {
            float amount = 0.0F;
            if (compareDate(&account->transactions[i].date, &date) == 0)
            {
                amount = account->transactions[i].amount;
                sum += amount;
                printf("%02d/%02d/%04d\t\t%15.2f\t\t\t%40s\t\t\t%11.2f\n", date.day, date.month, date.year, amount, account->transactions[i].info, sum);
            }
        }
    }
}