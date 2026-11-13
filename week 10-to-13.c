#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_ROOMS 10

typedef struct {
    int id;
    char name[50];
    int roomNo;
} Student;

typedef struct {
    int roomNo;
    int capacity;
    int occupied;
} Room;

typedef struct {
    int studentId;
    int amount;
} Fee;

typedef struct {
    int studentId;
    char complaintText[100];
} Complaint;

void studentManagement(Student students[], int *count);
void roomManagement(Room rooms[], int maxRooms);
void feeManagement(Fee fees[], int *feeCount, Student students[], int studentCount);
void complaintManagement(Complaint complaints[], int *compCount, Student students[], int studentCount);

int main() {
    int choice;
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    Room rooms[MAX_ROOMS] = {
        {101, 2, 0}, {102, 2, 0}, {103, 2, 0}, {104, 2, 0}, {105, 2, 0},
        {106, 2, 0}, {107, 2, 0}, {108, 2, 0}, {109, 2, 0}, {110, 2, 0}
    };

    Fee fees[MAX_STUDENTS];
    int feeCount = 0;

    Complaint complaints[50];
    int complaintCount = 0;

    do {
        printf("\n--- HOSTEL MANAGEMENT SYSTEM ---\n");
        printf("1. Student Management\n");
        printf("2. Room Management\n");
        printf("3. Fee Management\n");
        printf("4. Complaint Management\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                studentManagement(students, &studentCount);
                break;
            case 2:
                roomManagement(rooms, MAX_ROOMS);
                break;
            case 3:
                feeManagement(fees, &feeCount, students, studentCount);
                break;
            case 4:
                complaintManagement(complaints, &complaintCount, students, studentCount);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void studentManagement(Student students[], int *count) {
    int choice;
    do {
        printf("\n--- STUDENT MANAGEMENT ---\n");
        printf("1. Register Student\n");
        printf("2. View Students\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (*count < MAX_STUDENTS) {
                    printf("Enter Student ID: ");
                    scanf("%d", &students[*count].id);
                    printf("Enter Student Name: ");
                    scanf("%s", students[*count].name);
                    printf("Enter Allocated Room No: ");
                    scanf("%d", &students[*count].roomNo);
                    (*count)++;
                    printf("Student registered successfully!\n");
                } else {
                    printf("Student list is full!\n");
                }
                break;
            case 2:
                printf("\n--- REGISTERED STUDENTS ---\n");
                for (int i = 0; i < *count; i++) {
                    printf("ID: %d | Name: %s | Room: %d\n", students[i].id, students[i].name, students[i].roomNo);
                }
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
}

void roomManagement(Room rooms[], int maxRooms) {
    int choice;
    do {
        printf("\n--- ROOM MANAGEMENT ---\n");
        printf("1. View Rooms\n");
        printf("2. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- ROOM STATUS ---\n");
                for (int i = 0; i < maxRooms; i++) {
                    printf("Room No: %d | Capacity: %d | Occupied: %d\n", rooms[i].roomNo, rooms[i].capacity, rooms[i].occupied);
                }
                break;
            case 2:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 2);
}

void feeManagement(Fee fees[], int *feeCount, Student students[], int studentCount) {
    int choice;
    do {
        printf("\n--- FEE MANAGEMENT ---\n");
        printf("1. Update Fee Status\n");
        printf("2. View Fees\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (studentCount > 0) {
                    int targetId, amount, found = 0;
                    printf("Enter Student ID: ");
                    scanf("%d", &targetId);
                    for (int i = 0; i < studentCount; i++) {
                        if (students[i].id == targetId) {
                            found = 1;
                            break;
                        }
                    }
                    if (found) {
                        fees[*feeCount].studentId = targetId;
                        printf("Enter Fee Amount: ");
                        scanf("%d", &amount);
                        fees[*feeCount].amount = amount;
                        (*feeCount)++;
                        printf("Fee updated successfully!\n");
                    } else {
                        printf("Student ID not found.\n");
                    }
                } else {
                    printf("No students registered yet.\n");
                }
                break;
            case 2:
                printf("\n--- FEE RECORDS ---\n");
                for (int i = 0; i < *feeCount; i++) {
                    printf("Student ID: %d | Fee Amount: %d\n", fees[i].studentId, fees[i].amount);
                }
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
}

void complaintManagement(Complaint complaints[], int *compCount, Student students[], int studentCount) {
    int choice;
    do {
        printf("\n--- COMPLAINT MANAGEMENT ---\n");
        printf("1. Add Complaint\n");
        printf("2. View Complaints\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (studentCount > 0) {
                    int targetId, found = 0;
                    printf("Enter Student ID: ");
                    scanf("%d", &targetId);
                    for (int i = 0; i < studentCount; i++) {
                        if (students[i].id == targetId) {
                            found = 1;
                            break;
                        }
                    }
                    if (found) {
                        complaints[*compCount].studentId = targetId;
                        printf("Enter complaint description: ");
                        scanf("%s", complaints[*compCount].complaintText);
                        (*compCount)++;
                        printf("Complaint added successfully!\n");
                    } else {
                        printf("Student ID not found.\n");
                    }
                } else {
                    printf("No students registered yet.\n");
                }
                break;
            case 2:
                printf("\n--- COMPLAINT LIST ---\n");
                for (int i = 0; i < *compCount; i++) {
                    printf("Student ID: %d | Complaint: %s\n", complaints[i].studentId, complaints[i].complaintText);
                }
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
}