#include "stdnt.h"

void clear() {
    while (getchar() != '\n');
}

void clrscr() {
    #ifdef _WIN32
    system("cls");
    #endif
    #ifdef linux
    system("clear");
    #endif
}

void addNode(Student** first, node nod) {
    if (*first == NULL) {
        *first = (Student*)malloc(sizeof(Student));
        (*first)->stdnt = nod;
        (*first)->next = *first;
        (*first)->prev = *first;
    } else {
        Student* newStdnt = (Student*)malloc(sizeof(Student));
        Student* last = (*first)->prev;
        newStdnt->stdnt = nod;
        newStdnt->next = *first;
        newStdnt->prev = last;
        (*first)->prev = newStdnt;
        last->next = newStdnt;
    }
}

void addStudents(Student** first, int n) {
    for (int i = 0; i < n; i++) {
        node temp;
        enterName(temp.name);
        enterClass(temp.Class);
        enterPhone(temp.phone);
        enterGrade(&temp.grade);
        addNode(first, temp);
    }
}

void freeList(Student *first) {
    if (first == NULL)
        return;
    Student* f = NULL;
    Student* temp = first;
    do {
        f = temp;
        temp = temp->next;
        free(f);
    } while (temp != first);
}

void loadFile(Student** first) {
    static int loaded = 0;
    if (loaded)
        return;
    int pr = 0;
    do {
        pr = 2;
        printf("\nDo you want to preload data from file?\n1. yes\n0. no\n");
        scanf("%d", &pr);
        clear();
        if (pr == 0)
            return;
        if (pr != 1)
            printf("\n\nDon't have that choice\n");
    } while (pr != 1);
    pr = 0;
    FILE* f = fopen(fileName, "r");
    if (f == NULL)
        return;
    node nod;
    while (fscanf(f, "%s %s %s %f", nod.name, nod.Class, nod.phone, &nod.grade) != EOF) {
        addNode(first, nod);
        pr++;
    }
    fclose(f);
    printf("\n%d record", pr);
    if (pr < 2) printf(" loaded\n");
    else printf("s loaded\n");
    loaded = 1;
}

void saveFile(Student* first) {
    int save = 0;
    do {
        clrscr();
        save = -1;
        printf("\nDo you want to save modified?\n1. Yes\n0. No\n");
        scanf("%d", &save);
        clear();
    } while (save < 0 || save > 1);
    if (!save || first == NULL) return;
    FILE* f = fopen(fileName, "w");
    Student* temp = first;
    do {
        fprintf(f, "%s %s %s %g\n", temp->stdnt.name, temp->stdnt.Class, temp->stdnt.phone, temp->stdnt.grade);
        temp = temp->next;
    } while (temp != first);
    fclose(f);
}

void printNameGrade(Student* first) {
    if (first == NULL) {
        printf("\nList is empty\n");
        return;
    }
    int i = 0;
    printf("%-4s %-20s %-3s\n", "STT", "Name", "Grade");
    Student* temp = first;
    do {
        printf("%-4d %-20s %-3g\n", ++i, temp->stdnt.name, temp->stdnt.grade);
        temp = temp->next;
    } while (temp != first);
}

void printMenu() {
    printf("\nstudents management\n\n");
    printf(
        "1. Input data\n2. Print list\n3. Search by name and class\n4. Filter by class\n5. Sort by grade\n6. "
        "Quit\n\nYour choice? ");
}

void choice(int* lc) {
    do {
        clrscr();
        *lc = 0;
        printMenu();
        scanf("%d", lc);
        clear();
        if (*lc < 1 || *lc > 6) {
            printf("\n\nDon't have that choice, press Enter to retry ");
            getchar();
        }
    } while (*lc < 1 || *lc > 6);
}

void StdntsManagement() {
    Student* first = NULL;
    int lc = 0;
    do {
        clrscr();
        choice(&lc);
        clrscr();
        switch (lc) {
        case 1:
            inputData(&first);
            break;
        case 2:
            printList(first);
            break;
        case 3:
            search(first);
            break;
        case 4:
            filtByClass(first);
            break;
        case 5:
            sortByGrade(first);
            break;
        case 6:
            saveFile(first);
            break;
        }
        if (lc != 1 && lc != 6) {
            printf("\nPress Enter to continue ");
            getchar();
        }
    } while (lc != 6);
    freeList(first);
}
void inputData(Student** first) {
    int pr = 0;
    loadFile(first);
    do {
        pr = 0;
        printf("\nEnter number stdent you want to input: ");
        scanf("%d", &pr);
        clear();
        if (pr < 0)
            printf("\nNumber of student must be geater than 0\n");
    } while (pr < 0);
    addStudents(first, pr);
}

void printList(Student* first) {
    char type = 0;
    do {
        type = 0;
        printf("\n1. Print by name and grade\n2. Print all list\n");
        scanf("%d", &type);
        clear();
        if (type < 1 || type > 2)
            printf("\nDon't have that choice\n");
    } while (type < 1 || type > 2);
    clrscr();
    if (type == 1)
        printNameGrade(first);
    else
        printAllList(first);
}

void printAllList(Student* first) {
    if (first == NULL) {
        printf("\nList is empty\n");
        return;
    }
    int i = 0;
    printf("%-4s %-20s %-8s %-12s %-5s\n", "STT", "Name", "Class", "Phone", "Grade");
    Student* temp = first;
    do {
        printf("%-4d %-20s %-8s %-12s %-5g\n", ++i, temp->stdnt.name, temp->stdnt.Class, temp->stdnt.phone, temp->stdnt.grade);
        temp = temp->next;
    } while (temp != first);
}

void search(Student* frist) {
    if (frist == NULL) {
        printf("\nList is empty\n");
        return;
    }
    Student* second = NULL;
    int count = 0;
    char Class[30], name[100];
    printf("\nEnter the class which you want to find: ");
    scanf("%[^\n]s", Class);
    clear();
    printf("\nEnter the name which you want to find: ");
    scanf("%[^\n]s\n", name);
    clear();
    Student* temp = frist;
    do {
        if (strStr(temp->stdnt.Class, Class) != NULL && strStr(temp->stdnt.name, name) != NULL) {
            addNode(&second, temp->stdnt);
            count++;
        }
        temp = temp->next;
    } while (temp != frist);
    if (count) {
        printf("\nFound %d resutl", count);
        if (count > 1)
            printf("s\n");
        else
            printf("\n");
        printAllList(second);
    } else {
        printf("\nNo result\n");
    }
    freeList(second);
}

void filtByClass(Student* first) {
    if (first == NULL) {
        printf("\nList is empty\n");
        return;
    }
    char class[15];
    printf("\nEnter the class which you want to disable: ");
    scanf("%[^\n]s", class);
    clear();
    clrscr();
    printf("%-3s %-20s %-8s %-12s %-5s\n", "STT", "Name", "Class", "Phone", "Grade");
    int i = 0;
    Student* temp = first;
    do {
        if (compare(temp->stdnt.Class, class)) {
            printf("%-3d %-20s %-8s %-12s %-5g\n", ++i, temp->stdnt.name, temp->stdnt.Class, temp->stdnt.phone, temp->stdnt.grade);
        }
        temp = temp->next;
    } while (temp != first);
}

void swap(Student *st1, Student *st2) {
    node temp = st1->stdnt;
    st1->stdnt = st2->stdnt;
    st2->stdnt = temp;
}

void sortByGrade(Student *first) {
    if (first == NULL || first == first->next) return;
    for (Student *temp = first; temp != first->prev; temp = temp->next) {
        Student *temp2 = temp->next;
        do {
            if (temp->stdnt.grade < temp2->stdnt.grade) swap(temp, temp2);
            temp2 = temp2->next;
        } while (temp2 != first);
    }
    printAllList(first);
}

int compare(const char *s1, const char *s2) {
    char str1[100], str2[100];
    strcpy(str1, s1);
    strcpy(str2, s2);
    for (int i = 0; i < strlen(str1); i++) str1[i] = tolower(str1[i]);
    for (int i = 0; i < strlen(str2); i++) str2[i] = tolower(str2[i]);
    return strcmp(str1, str2);
}

char *strStr(const char *s1, const char *s2) {
    static char str1[100], str2[100];
    strcpy(str1, s1);
    strcpy(str2, s2);
    for (int i = 0; i < strlen(str1); i++) str1[i] = tolower(str1[i]);
    for (int i = 0; i < strlen(str2); i++) str2[i] = tolower(str2[i]);
    return strstr(str1, str2);
}

void enterName(char *name) {
    clrscr();
    printf("\nEnter name: ");
    scanf("%[^\n]s", name);
    clear();
}

void enterClass(char *class) {
    clrscr();
    printf("\nEnter class: ");
    scanf("%[^\n]s", class);
    clear();
}

void enterPhone(char *phone) {
    int p = 0;
    do {
        clrscr();
        printf("\nEnter phone number: ");
        scanf("%[^\n]s", phone);
        clear();
        p = strlen(phone);
        if (p < 6 || p > 10) {
            printf("\nInvalid phone number, press Enter to retry ");
            getchar();
        }
    } while (p < 6 || p > 10);
}

void enterGrade(float *grade) {
    do {
        clrscr();
        printf("\nEnter grade: ");
        scanf("%f", grade);
        clear();
        if (*grade < 0 || *grade > 10) {
            printf("\nGrade must be greater than or equal to 0 and less than or equal to 10, press Enter to retry ");
            getchar();
        }
    } while (*grade < 0 || *grade > 10);
}