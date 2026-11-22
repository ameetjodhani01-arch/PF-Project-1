
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLOORS 2
#define ROOMS_PER_FLOOR 5

typedef struct {
    int id;
    char name[50];
    char contact[20];
    int roomNo;
    int status;
} Student;

typedef struct {
    int roomNo;
    char type[20];
    int capacity;
    int occupancy;
} Room;

typedef struct {
    int studentId;
    float amount;
    int paid;
} Fee;

typedef struct {
    int studentId;
    char description[100];
    int status;
} Complaint;

Student *students = NULL;
Room *rooms = NULL;
Fee *fees = NULL;
Complaint *complaints = NULL;

int studentCount = 0;
int roomCount = 0;
int feeCount = 0;
int complaintCount = 0;

int **occupancy = NULL;

int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

void clearInput() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void initializeRooms() {
    rooms = malloc(10 * sizeof(Room));

    if (rooms == NULL) {
        printf("Room memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < 10; i++) {
        rooms[i].roomNo = (i / 5 + 1) * 100 + (i % 5 + 1);
        strcpy(rooms[i].type, "Standard");
        rooms[i].capacity = 2;
        rooms[i].occupancy = 0;
    }

    roomCount = 10;

    occupancy = malloc(FLOORS * sizeof(int *));

    if (occupancy == NULL) {
        printf("Memory allocation failed.\n");
        free(rooms);
        exit(1);
    }

    for (int i = 0; i < FLOORS; i++) {
        occupancy[i] = calloc(ROOMS_PER_FLOOR, sizeof(int));

        if (occupancy[i] == NULL) {
            printf("Memory allocation failed.\n");

            for (int j = 0; j < i; j++) {
                free(occupancy[j]);
            }

            free(occupancy);
            free(rooms);
            exit(1);
        }
    }
}

void addStudent() {
    Student *temp = realloc(students, (studentCount + 1) * sizeof(Student));

    if (temp == NULL) {
        printf("Student memory allocation failed.\n");
        return;
    }

    students = temp;

    Student *ptr = &students[studentCount];

    printf("Enter Student ID: ");
    ptr->id = readInt();
    clearInput();

    printf("Enter Student Name: ");
    fgets(ptr->name, sizeof(ptr->name), stdin);
    ptr->name[strcspn(ptr->name, "\n")] = '\0';

    printf("Enter Contact: ");
    fgets(ptr->contact, sizeof(ptr->contact), stdin);
    ptr->contact[strcspn(ptr->contact, "\n")] = '\0';

    ptr->roomNo = 0;
    ptr->status = 1;

    studentCount++;

    printf("Student registered successfully.\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No student records found.\n");
        return;
    }

    Student *ptr = students;

    for (int i = 0; i < studentCount; i++, ptr++) {
        printf("\nID: %d", ptr->id);
        printf("\nName: %s", ptr->name);
        printf("\nContact: %s", ptr->contact);
        printf("\nRoom: %d", ptr->roomNo);
        printf("\nStatus: %s\n", ptr->status ? "Active" : "Inactive");
    }
}

void searchStudent() {
    int id, found = 0;

    printf("Enter Student ID: ");
    id = readInt();

    Student *ptr = students;

    for (int i = 0; i < studentCount; i++, ptr++) {
        if (ptr->id == id) {
            printf("\nStudent Found");
            printf("\nName: %s", ptr->name);
            printf("\nContact: %s", ptr->contact);
            printf("\nRoom: %d\n", ptr->roomNo);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

void displayRooms() {
    Room *ptr = rooms;

    for (int i = 0; i < roomCount; i++, ptr++) {
        printf("\nRoom Number: %d", ptr->roomNo);
        printf("\nType: %s", ptr->type);
        printf("\nCapacity: %d", ptr->capacity);
        printf("\nOccupied: %d", ptr->occupancy);
        printf("\nVacant: %d\n", ptr->capacity - ptr->occupancy);
    }
}

void allocateRoom() {
    int id, roomNo;
    Student *student = NULL;
    Room *room = NULL;

    printf("Enter Student ID: ");
    id = readInt();

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            student = &students[i];
            break;
        }
    }

    if (student == NULL) {
        printf("Student not found.\n");
        return;
    }

    if (student->roomNo != 0) {
        printf("Student already has a room.\n");
        return;
    }

    printf("Enter Room Number: ");
    roomNo = readInt();

    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].roomNo == roomNo) {
            room = &rooms[i];
            break;
        }
    }

    if (room == NULL) {
        printf("Room not found.\n");
        return;
    }

    if (room->occupancy >= room->capacity) {
        printf("Room is full.\n");
        return;
    }

    room->occupancy++;

    int floor = roomNo / 100 - 1;
    int index = roomNo % 100 - 1;

    if (floor >= 0 && floor < FLOORS &&
        index >= 0 && index < ROOMS_PER_FLOOR) {
        occupancy[floor][index]++;
    }

    student->roomNo = roomNo;

    printf("Room allocated successfully.\n");
}

void displayOccupancy() {
    printf("\nHostel Occupancy Map\n");

    for (int i = 0; i < FLOORS; i++) {
        printf("\nFloor %d: ", i + 1);

        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            printf("%d ", occupancy[i][j]);
        }
    }

    printf("\n");
}

void manageFees() {
    int id, choice;
    float amount;

    printf("Enter Student ID: ");
    id = readInt();

    printf("Enter Fee Amount: ");
    scanf("%f", &amount);

    printf("1. Paid\n2. Unpaid\nChoice: ");
    choice = readInt();

    Fee *temp = realloc(fees, (feeCount + 1) * sizeof(Fee));

    if (temp == NULL) {
        printf("Fee memory allocation failed.\n");
        return;
    }

    fees = temp;

    Fee *ptr = &fees[feeCount];

    ptr->studentId = id;
    ptr->amount = amount;
    ptr->paid = (choice == 1);

    feeCount++;

    printf("Fee record saved successfully.\n");
}

void displayFees() {
    if (feeCount == 0) {
        printf("No fee records found.\n");
        return;
    }

    Fee *ptr = fees;

    for (int i = 0; i < feeCount; i++, ptr++) {
        printf("\nStudent ID: %d", ptr->studentId);
        printf("\nAmount: %.2f", ptr->amount);
        printf("\nStatus: %s\n", ptr->paid ? "Paid" : "Unpaid");
    }
}

void addComplaint() {
    Complaint *temp = realloc(
        complaints,
        (complaintCount + 1) * sizeof(Complaint)
    );

    if (temp == NULL) {
        printf("Complaint memory allocation failed.\n");
        return;
    }

    complaints = temp;

    Complaint *ptr = &complaints[complaintCount];

    printf("Enter Student ID: ");
    ptr->studentId = readInt();
    clearInput();

    printf("Enter Complaint Description: ");
    fgets(ptr->description, sizeof(ptr->description), stdin);
    ptr->description[strcspn(ptr->description, "\n")] = '\0';

    ptr->status = 0;

    complaintCount++;

    printf("Complaint submitted successfully.\n");
}

void displayComplaints() {
    if (complaintCount == 0) {
        printf("No complaints found.\n");
        return;
    }

    Complaint *ptr = complaints;

    for (int i = 0; i < complaintCount; i++, ptr++) {
        printf("\nStudent ID: %d", ptr->studentId);
        printf("\nDescription: %s", ptr->description);
        printf("\nStatus: %s\n",
               ptr->status ? "Resolved" : "Pending");
    }
}

void updateComplaint() {
    int index;

    if (complaintCount == 0) {
        printf("No complaints available.\n");
        return;
    }

    displayComplaints();

    printf("\nEnter complaint index: ");
    index = readInt();

    if (index < 1 || index > complaintCount) {
        printf("Invalid complaint index.\n");
        return;
    }

    Complaint *ptr = &complaints[index - 1];

    ptr->status = 1;

    printf("Complaint marked as resolved.\n");
}

void freeMemory() {
    free(students);
    free(rooms);
    free(fees);
    free(complaints);

    if (occupancy != NULL) {
        for (int i = 0; i < FLOORS; i++) {
            free(occupancy[i]);
        }

        free(occupancy);
    }

    students = NULL;
    rooms = NULL;
    fees = NULL;
    complaints = NULL;
    occupancy = NULL;
}

int main() {
    int choice;

    initializeRooms();

    do {
        printf("\n===== HOSTEL MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Display Rooms\n");
        printf("5. Allocate Room\n");
        printf("6. Display Occupancy\n");
        printf("7. Manage Fees\n");
        printf("8. Display Fees\n");
        printf("9. Add Complaint\n");
        printf("10. Display Complaints\n");
        printf("11. Resolve Complaint\n");
        printf("0. Exit\n");

        printf("Enter Choice: ");
        choice = readInt();

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                displayRooms();
                break;

            case 5:
                allocateRoom();
                break;

            case 6:
                displayOccupancy();
                break;

            case 7:
                manageFees();
                break;

            case 8:
                displayFees();
                break;

            case 9:
                addComplaint();
                break;

            case 10:
                displayComplaints();
                break;

            case 11:
                updateComplaint();
                break;

            case 0:
                freeMemory();
                printf("Memory released. Program terminated.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    return 0;
}
