
#include <stdio.h>

int main() {
    int studentIDs[50];
    int studentFloors[50];
    int studentRooms[50];
    int feePaid[50];
    int complaintStatus[50];

    int roomStatus[3][4] = {0};

    int studentCount = 0;
    int choice, subChoice;
    int i, j, k;
    int id, index;
    int floor, room;
    int totalOccupied, totalVacant;
    int paidCount, unpaidCount;
    int pendingCount, resolvedCount;
    int found, valid;

    do {
        printf("\n========== HOSTEL MANAGEMENT SYSTEM ==========\n");
        printf("1. Student Management\n");
        printf("2. Room Management\n");
        printf("3. Fee Management\n");
        printf("4. Complaint Management\n");
        printf("5. Hostel Information and Reports\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        valid = scanf("%d", &choice);

        if (valid != 1) {
            printf("Invalid input. Enter a number.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                do {
                    printf("\n---------- STUDENT MANAGEMENT ----------\n");
                    printf("1. Register Student\n");
                    printf("2. Display All Students\n");
                    printf("3. Search Student by ID\n");
                    printf("4. Return to Main Menu\n");
                    printf("Enter your choice: ");

                    if (scanf("%d", &subChoice) != 1) {
                        printf("Invalid input.\n");
                        while (getchar() != '\n');
                        subChoice = 0;
                        continue;
                    }

                    switch (subChoice) {
                        case 1:
                            if (studentCount >= 50) {
                                printf("Student record limit reached.\n");
                                break;
                            }

                            printf("Enter Student ID: ");
                            if (scanf("%d", &id) != 1) {
                                printf("Invalid ID.\n");
                                while (getchar() != '\n');
                                break;
                            }

                            found = 0;

                            for (i = 0; i < studentCount; i++) {
                                if (studentIDs[i] == id) {
                                    found = 1;
                                    break;
                                }
                            }

                            if (found) {
                                printf("Student ID already exists.\n");
                            } else {
                                studentIDs[studentCount] = id;
                                studentFloors[studentCount] = -1;
                                studentRooms[studentCount] = -1;
                                feePaid[studentCount] = 0;
                                complaintStatus[studentCount] = 0;

                                studentCount++;

                                printf("Student registered successfully.\n");
                                printf("Use Room Management to allocate a room.\n");
                            }
                            break;

                        case 2:
                            if (studentCount == 0) {
                                printf("No student records available.\n");
                            } else {
                                printf("\nID\tFloor\tRoom\tFee\tComplaint\n");

                                for (i = 0; i < studentCount; i++) {
                                    printf("%d\t", studentIDs[i]);

                                    if (studentFloors[i] == -1) {
                                        printf("Not Assigned\t");
                                    } else {
                                        printf("%d\t%d\t",
                                               studentFloors[i] + 1,
                                               studentRooms[i] + 1);
                                    }

                                    printf("%s\t",
                                           feePaid[i] ? "Paid" : "Unpaid");

                                    if (complaintStatus[i] == 0) {
                                        printf("None\n");
                                    } else if (complaintStatus[i] == 1) {
                                        printf("Pending\n");
                                    } else {
                                        printf("Resolved\n");
                                    }
                                }
                            }
                            break;

                        case 3:
                            printf("Enter Student ID to search: ");

                            if (scanf("%d", &id) != 1) {
                                printf("Invalid ID.\n");
                                while (getchar() != '\n');
                                break;
                            }

                            found = 0;

                            for (i = 0; i < studentCount; i++) {
                                if (studentIDs[i] == id) {
                                    found = 1;

                                    printf("\nStudent ID: %d\n",
                                           studentIDs[i]);

                                    if (studentFloors[i] == -1) {
                                        printf("Room: Not allocated\n");
                                    } else {
                                        printf("Floor: %d\n",
                                               studentFloors[i] + 1);
                                        printf("Room: %d\n",
                                               studentRooms[i] + 1);
                                    }

                                    printf("Fee Status: %s\n",
                                           feePaid[i] ? "Paid" : "Unpaid");

                                    if (complaintStatus[i] == 0) {
                                        printf("Complaint Status: None\n");
                                    } else if (complaintStatus[i] == 1) {
                                        printf("Complaint Status: Pending\n");
                                    } else {
                                        printf("Complaint Status: Resolved\n");
                                    }

                                    break;
                                }
                            }

                            if (!found) {
                                printf("Student not found.\n");
                            }
                            break;

                        case 4:
                            printf("Returning to main menu.\n");
                            break;

                        default:
                            printf("Invalid choice.\n");
                    }

                } while (subChoice != 4);
                break;

            case 2:
                do {
                    printf("\n---------- ROOM MANAGEMENT ----------\n");
                    printf("1. Display Room Layout\n");
                    printf("2. Allocate Room to Student\n");
                    printf("3. Search for Available Room\n");
                    printf("4. Room Occupancy Report\n");
                    printf("5. Return to Main Menu\n");
                    printf("Enter your choice: ");

                    if (scanf("%d", &subChoice) != 1) {
                        printf("Invalid input.\n");
                        while (getchar() != '\n');
                        subChoice = 0;
                        continue;
                    }

                    switch (subChoice) {
                        case 1:
                            printf("\nRoom Layout (0 = Vacant, 1 = Occupied)\n");

                            for (i = 0; i < 3; i++) {
                                printf("Floor %d: ", i + 1);

                                for (j = 0; j < 4; j++) {
                                    printf("Room %d [%s]  ",
                                           j + 1,
                                           roomStatus[i][j] == 0
                                               ? "Vacant" : "Occupied");
                                }

                                printf("\n");
                            }
                            break;

                        case 2:
                            printf("Enter Student ID: ");

                            if (scanf("%d", &id) != 1) {
                                printf("Invalid ID.\n");
                                while (getchar() != '\n');
                                break;
                            }

                            index = -1;

                            for (i = 0; i < studentCount; i++) {
                                if (studentIDs[i] == id) {
                                    index = i;
                                    break;
                                }
                            }

                            if (index == -1) {
                                printf("Student not found. Register first.\n");
                                break;
                            }

                            if (studentFloors[index] != -1) {
                                printf("Student already has a room.\n");
                                break;
                            }

                            printf("Enter Floor (1-3): ");

                            if (scanf("%d", &floor) != 1) {
                                printf("Invalid floor.\n");
                                while (getchar() != '\n');
                                break;
                            }

                            printf("Enter Room Number (1-4): ");

                            if (scanf("%d", &room) != 1) {
                                printf("Invalid room number.\n");
                                while (getchar() != '\n');
                                break;
                            }

                            if (floor < 1 || floor > 3 ||
                                room < 1 || room > 4) {
                                printf("Invalid floor or room number.\n");
                            } else if (roomStatus[floor - 1][room - 1] == 1) {
                                printf("Room is already occupied.\n");
                            } else {
                                roomStatus[floor - 1][room - 1] = 1;
                                studentFloors[index] = floor - 1;
                                studentRooms[index] = room - 1;

                                printf("Room allocated successfully.\n");
                            }
                            break;

                        case 3:
                            found = 0;

                            for (i = 0; i < 3; i++) {
                                for (j = 0; j < 4; j++) {
                                    if (roomStatus[i][j] == 0) {
                                        printf("Available: Floor %d, Room %d\n",
                                               i + 1, j + 1);
                                        found = 1;
                                    }
                                }
                            }

                            if (!found) {
                                printf("No rooms are available.\n");
                            }
                            break;

                        case 4:
                            totalOccupied = 0;
                            totalVacant = 0;

                            printf("\n---------- OCCUPANCY REPORT ----------\n");

                            for (i = 0; i < 3; i++) {
                                int floorOccupied = 0;

                                for (j = 0; j < 4; j++) {
                                    if (roomStatus[i][j] == 1) {
                                        floorOccupied++;
                                    }
                                }

                                printf("Floor %d: %d occupied, %d vacant\n",
                                       i + 1,
                                       floorOccupied,
                                       4 - floorOccupied);

                                totalOccupied += floorOccupied;
                                totalVacant += 4 - floorOccupied;
                            }

                            printf("Total Rooms: 12\n");
                            printf("Total Occupied: %d\n", totalOccupied);
                            printf("Total Vacant: %d\n", totalVacant);
                            break;

                        case 5:
                            printf("Returning to main menu.\n");
                            break;

                        default:
                            printf("Invalid choice.\n");
                    }

                } while (subChoice != 5);
                break;

            case 3:
                printf("\n---------- FEE MANAGEMENT ----------\n");
                printf("1. Mark Student Fee as Paid\n");
                printf("2. Display Fee Report\n");
                printf("Enter your choice: ");

                if (scanf("%d", &subChoice) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (subChoice == 1) {
                    printf("Enter Student ID: ");

                    if (scanf("%d", &id) != 1) {
                        printf("Invalid ID.\n");
                        while (getchar() != '\n');
                        break;
                    }

                    found = 0;

                    for (i = 0; i < studentCount; i++) {
                        if (studentIDs[i] == id) {
                            feePaid[i] = 1;
                            found = 1;
                            printf("Fee marked as paid.\n");
                            break;
                        }
                    }

                    if (!found) {
                        printf("Student not found.\n");
                    }
                } else if (subChoice == 2) {
                    paidCount = 0;
                    unpaidCount = 0;

                    for (i = 0; i < studentCount; i++) {
                        if (feePaid[i] == 1) {
                            paidCount++;
                        } else {
                            unpaidCount++;
                        }
                    }

                    printf("Total Students: %d\n", studentCount);
                    printf("Fees Paid: %d\n", paidCount);
                    printf("Fees Unpaid: %d\n", unpaidCount);
                } else {
                    printf("Invalid choice.\n");
                }
                break;

            case 4:
                printf("\n---------- COMPLAINT MANAGEMENT ----------\n");
                printf("1. Register Complaint\n");
                printf("2. Mark Complaint as Resolved\n");
                printf("3. Display Complaint Report\n");
                printf("Enter your choice: ");

                if (scanf("%d", &subChoice) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (subChoice == 1 || subChoice == 2) {
                    printf("Enter Student ID: ");

                    if (scanf("%d", &id) != 1) {
                        printf("Invalid ID.\n");
                        while (getchar() != '\n');
                        break;
                    }

                    found = 0;

                    for (i = 0; i < studentCount; i++) {
                        if (studentIDs[i] == id) {
                            found = 1;

                            if (subChoice == 1) {
                                complaintStatus[i] = 1;
                                printf("Complaint registered as pending.\n");
                            } else if (complaintStatus[i] == 0) {
                                printf("No complaint is registered.\n");
                            } else {
                                complaintStatus[i] = 2;
                                printf("Complaint marked as resolved.\n");
                            }

                            break;
                        }
                    }

                    if (!found) {
                        printf("Student not found.\n");
                    }
                } else if (subChoice == 3) {
                    pendingCount = 0;
                    resolvedCount = 0;

                    printf("\nStudent ID\tComplaint Status\n");

                    for (i = 0; i < studentCount; i++) {
                        if (complaintStatus[i] == 1) {
                            printf("%d\t\tPending\n", studentIDs[i]);
                            pendingCount++;
                        } else if (complaintStatus[i] == 2) {
                            printf("%d\t\tResolved\n", studentIDs[i]);
                            resolvedCount++;
                        }
                    }

                    printf("Pending Complaints: %d\n", pendingCount);
                    printf("Resolved Complaints: %d\n", resolvedCount);

                    if (pendingCount == 0 && resolvedCount == 0) {
                        printf("No complaints recorded.\n");
                    }
                } else {
                    printf("Invalid choice.\n");
                }
                break;

            case 5:
                totalOccupied = 0;
                totalVacant = 0;
                paidCount = 0;
                unpaidCount = 0;
                pendingCount = 0;
                resolvedCount = 0;

                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 4; j++) {
                        if (roomStatus[i][j] == 1) {
                            totalOccupied++;
                        } else {
                            totalVacant++;
                        }
                    }
                }

                for (i = 0; i < studentCount; i++) {
                    if (feePaid[i] == 1) {
                        paidCount++;
                    } else {
                        unpaidCount++;
                    }

                    if (complaintStatus[i] == 1) {
                        pendingCount++;
                    } else if (complaintStatus[i] == 2) {
                        resolvedCount++;
                    }
                }

                printf("\n========== HOSTEL SUMMARY REPORT ==========\n");
                printf("Registered Students: %d\n", studentCount);
                printf("Total Rooms: 12\n");
                printf("Occupied Rooms: %d\n", totalOccupied);
                printf("Vacant Rooms: %d\n", totalVacant);
                printf("Fees Paid: %d\n", paidCount);
                printf("Fees Unpaid: %d\n", unpaidCount);
                printf("Pending Complaints: %d\n", pendingCount);
                printf("Resolved Complaints: %d\n", resolvedCount);
                break;

            case 6:
                printf("Thank you for using the Hostel Management System.\n");
                break;

            default:
                printf("Invalid main menu choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
