#include <stdio.h>
#include <string.h>

struct Name
{
    char firstName[20], middleName[20], lastName[20];
};

struct Date
{
    int day, month, year;
};

struct Address
{
    int number;
    char street[20], city[20], country[20], zip[20];
    struct Date sinceDate;
};

struct HumanRecord
{
    int id;
    struct Name name;
    struct Date birthDate;
    int adressCounter;
    struct Address addressList[10];
};

void initHuman(struct HumanRecord *human);
void moveHuman(struct HumanRecord *records, int size, int id, struct Address a);
void printHuman(const struct HumanRecord *human);


int main(int argc, char const *argv[])
{
    struct HumanRecord humanList[100];
    // struct Date date;
    // scanf("%d/%d/%d", &date.day, &date.month, &date.year);
    // printf("%d/%d/%d", date.day, date.month, date.year);
    initHuman(humanList+0);
    struct Address a = {20, "a", "b", "c", "d", {20,1,2020}};
    moveHuman(humanList, 1, 123, a);
    printHuman(humanList);
    return 0;
}

void initHuman(struct HumanRecord *human)
{
    printf("ID> ");
    scanf("%d", &human->id);
    printf("First Name> ");
    scanf("%s", human->name.firstName);
    printf("Middle Name> ");
    scanf("%s", human->name.middleName);
    printf("Last Name> ");
    scanf("%s", human->name.lastName);
    printf("Birth Date: day month year> ");
    scanf("%d %d %d", &human->birthDate.day, &human->birthDate.month, &human->birthDate.year);
    human->adressCounter = 1;
    printf("Address: number street city country zip> ");
    scanf("%d %s %s %s %s", &human->addressList[0].number, human->addressList[0].street, human->addressList[0].city, human->addressList[0].country, human->addressList[0].zip);
    printf("Since Date: day month year> ");
    scanf("%d %d %d", &human->addressList[0].sinceDate.day, &human->addressList[0].sinceDate.month, &human->addressList[0].sinceDate.year);
}

void shiftAddressArray(struct Address *addressList)
{
    for(int i = 9; i > 0; i--)
        addressList[i] = addressList[i-1];
}

void moveHuman(struct HumanRecord *records, int size, int id, struct Address a)
{
    for (int i = 0; i < size; i++)
    {
        if (records[i].id == id)
        {
            shiftAddressArray(records[i].addressList);
            records[i].adressCounter++;
            records[i].addressList[0] = a;
        }
    }
}

void printHuman(const struct HumanRecord *human)
{
    printf("ID: %d\n", human->id);
    printf("First Name: %s\n", human->name.firstName);
    printf("Middle Name: %s\n", human->name.middleName);
    printf("Last Name: %s\n", human->name.lastName);
    printf("Birth Date: day month year: %d %d %d\n", human->birthDate.day, human->birthDate.month, human->birthDate.year);
    printf("Addresses:\n");
    for (int i = 0; i < human->adressCounter; i++)
    {  
        printf("1:\n");
        printf("\t %d %s %s %s %s\n", human->addressList[i].number, human->addressList[i].street, human->addressList[i].city, human->addressList[0].country, human->addressList[0].zip);
        printf("\tSince Date: day month year: %d %d %d\n", human->addressList[i].sinceDate.day, human->addressList[i].sinceDate.month, human->addressList[i].sinceDate.year);
    }
}