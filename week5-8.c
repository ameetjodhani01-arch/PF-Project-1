#include <stdio.h>
#include <string.h>

int main()
{
    int studentIDs[50], studentAges[50], studentRooms[50];
    int roomNumbers[30], roomCapacities[30], roomOccupied[30];
    int feeStudentIDs[50], complaintIDs[50], complaintStudentIDs[50], complaintStatus[50];
    float totalFees[50], paidFees[50];
    int studentCount = 0, roomCount = 0, feeCount = 0, complaintCount = 0;
    int mainChoice, subChoice, i, j, found, validInput;
    int id, age, roomNo, capacity, available, selectedRoom;
    int complaintNo, complaintStudent, statusChoice;
    float total, paid;
    char roomType;
    int roomTypes[30];

    for (i = 0; i < 50; i++)
    {
        studentRooms[i] = 0;
    }

    printf("========================================\n");
    printf("       HOSTEL MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    do
    {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Student Management\n");
        printf("2. Room Management\n");
        printf("3. Fee Management\n");
        printf("4. Complaint Management\n");
        printf("5. Hostel Information\n");
        printf("6. Search / Reports\n");
        printf("7. Exit\n");

        do
        {
            printf("Enter your choice (1-7): ");
            validInput = scanf("%d", &mainChoice);
            if (validInput != 1)
            {
                printf("Please enter a number.\n");
                while (getchar() != '\n');
                mainChoice = 0;
            }
            else if (mainChoice < 1 || mainChoice > 7)
            {
                printf("Invalid choice. Enter a number from 1 to 7.\n");
            }
        } while (mainChoice < 1 || mainChoice > 7);

        switch (mainChoice)
        {
            case 1:
                do
                {
                    printf("\n========== STUDENT MANAGEMENT ==========\n");
                    printf("1. Register Student\n");
                    printf("2. Display All Students\n");
                    printf("3. Search Student by ID\n");
                    printf("4. Student Login\n");
                    printf("5. Back to Main Menu\n");

                    do
                    {
                        printf("Enter choice (1-5): ");
                        validInput = scanf("%d", &subChoice);
                        if (validInput != 1)
                        {
                            printf("Please enter a number.\n");
                            while (getchar() != '\n');
                            subChoice = 0;
                        }
                        else if (subChoice < 1 || subChoice > 5)
                        {
                            printf("Invalid choice. Try again.\n");
                        }
                    } while (subChoice < 1 || subChoice > 5);

                    switch (subChoice)
                    {
                        case 1:
                            if (studentCount == 50)
                            {
                                printf("Student list is full.\n");
                                break;
                            }

                            do
                            {
                                printf("Enter Student ID: ");
                                validInput = scanf("%d", &id);
                                if (validInput != 1)
                                {
                                    printf("Student ID must be numeric.\n");
                                    while (getchar() != '\n');
                                    id = 0;
                                }
                                else if (id <= 0)
                                {
                                    printf("Student ID must be greater than zero.\n");
                                }
                                else
                                {
                                    found = 0;
                                    for (i = 0; i < studentCount; i++)
                                    {
                                        if (studentIDs[i] == id)
                                        {
                                            found = 1;
                                        }
                                    }
                                    if (found)
                                    {
                                        printf("This Student ID already exists.\n");
                                        id = 0;
                                    }
                                }
                            } while (id <= 0);

                            do
                            {
                                printf("Enter Age (16-40): ");
                                validInput = scanf("%d", &age);
                                if (validInput != 1)
                                {
                                    printf("Age must be numeric.\n");
                                    while (getchar() != '\n');
                                    age = 0;
                                }
                                else if (age < 16 || age > 40)
                                {
                                    printf("Age must be between 16 and 40.\n");
                                }
                            } while (age < 16 || age > 40);

                            studentIDs[studentCount] = id;
                            studentAges[studentCount] = age;
                            studentRooms[studentCount] = 0;
                            studentCount++;

                            printf("Student registered successfully.\n");
                            printf("Student ID: %d\n", id);
                            printf("Age: %d\n", age);
                            break;

                        case 2:
                            if (studentCount == 0)
                            {
                                printf("No student records available.\n");
                            }
                            else
                            {
                                printf("\nStudent Records\n");
                                printf("----------------------------------------\n");
                                for (i = 0; i < studentCount; i++)
                                {
                                    printf("Student ID: %d | Age: %d | Room: ",
                                           studentIDs[i], studentAges[i]);
                                    if (studentRooms[i] == 0)
                                    {
                                        printf("Not allocated\n");
                                    }
                                    else
                                    {
                                        printf("%d\n", studentRooms[i]);
                                    }
                                }
                            }
                            break;

                        case 3:
                            if (studentCount == 0)
                            {
                                printf("No student records available.\n");
                                break;
                            }

                            printf("Enter Student ID to search: ");
                            validInput = scanf("%d", &id);
                            if (validInput != 1)
                            {
                                printf("Invalid Student ID.\n");
                                while (getchar() != '\n');
                                break;
                            }

                            found = 0;
                            for (i = 0; i < studentCount; i++)
                            {
                                if (studentIDs[i] == id)
                                {
                                    found = 1;
                                    printf("Student found.\n");
                                    printf("Student ID: %d\n", studentIDs[i]);
                                    printf("Age: %d\n", studentAges[i]);
                                    if (studentRooms[i] == 0)
                                    {
                                        printf("Room: Not allocated\n");
                                    }
                                    else
                                    {
                                        printf("Room: %d\n", studentRooms[i]);
                                    }
                                }
                            }
                            if (!found)
                            {
                                printf("Student ID not found.\n");
                            }
                            break;

                        case 4:
                            if (studentCount == 0)
                            {
                                printf("No registered students. Register first.\n");
                                break;
                            }
                            printf("Enter Student ID to login: ");
                            validInput = scanf("%d", &id);
                            if (validInput != 1)
                            {
                                printf("Invalid Student ID.\n");
                                while (getchar() != '\n');
                                break;
                            }
                            found = 0;
                            for (i = 0; i < studentCount; i++)
                            {
                                if (studentIDs[i] == id)
                                {
                                    found = 1;
                                    printf("Login successful. Welcome, Student %d.\n", id);
                                }
                            }
                            if (!found)
                            {
                                printf("Login failed. Student ID not found.\n");
                            }
                            break;

                        case 5:
                            printf("Returning to main menu.\n");
                            break;
                    }
                } while (subChoice != 5);
                break;

            case 2:
                do
                {
                    printf("\n========== ROOM MANAGEMENT ==========\n");
                    printf("1. Add Room\n");
                    printf("2. Display Rooms and Vacancy\n");
                    printf("3. Allocate Room to Student\n");
                    printf("4. Back to Main Menu\n");

                    do
                    {
                        printf("Enter choice (1-4): ");
                        validInput = scanf("%d", &subChoice);
                        if (validInput != 1)
                        {
                            printf("Please enter a number.\n");
                            while (getchar() != '\n');
                            subChoice = 0;
                        }
                        else if (subChoice < 1 || subChoice > 4)
                        {
                            printf("Invalid choice. Try again.\n");
                        }
                    } while (subChoice < 1 || subChoice > 4);

                    switch (subChoice)
                    {
                        case 1:
                            if (roomCount == 30)
                            {
                                printf("Room list is full.\n");
                                break;
                            }

                            do
                            {
                                printf("Enter Room Number: ");
                                validInput = scanf("%d", &roomNo);
                                if (validInput != 1)
                                {
                                    printf("Room number must be numeric.\n");
                                    while (getchar() != '\n');
                                    roomNo = 0;
                                }
                                else if (roomNo <= 0)
                                {
                                    printf("Room number must be greater than zero.\n");
                                }
                                else
                                {
                                    found = 0;
                                    for (i = 0; i < roomCount; i++)
                                    {
                                        if (roomNumbers[i] == roomNo)
                                        {
                                            found = 1;
                                        }
                                    }
                                    if (found)
                                    {
                                        printf("Room number already exists.\n");
                                        roomNo = 0;
                                    }
                                }
                            } while (roomNo <= 0);

                            do
                            {
                                printf("Room Type (S = Single, D = Double): ");
                                scanf(" %c", &roomType);
                                if (roomType != 'S' && roomType != 's' &&
                                    roomType != 'D' && roomType != 'd')
                                {
                                    printf("Enter S or D.\n");
                                }
                            } while (roomType != 'S' && roomType != 's' &&
                                     roomType != 'D' && roomType != 'd');

                            do
                            {
                                printf("Enter Room Capacity: ");
                                validInput = scanf("%d", &capacity);
                                if (validInput != 1)
                                {
                                    printf("Capacity must be numeric.\n");
                                    while (getchar() != '\n');
                                    capacity = 0;
                                }
                                else if (capacity <= 0 || capacity > 10)
                                {
                                    printf("Capacity must be between 1 and 10.\n");
                                }
                            } while (capacity <= 0 || capacity > 10);

                            roomNumbers[roomCount] = roomNo;
                            roomCapacities[roomCount] = capacity;
                            roomOccupied[roomCount] = 0;
                            if (roomType == 'S' || roomType == 's')
                            {
                                roomTypes[roomCount] = 1;
                            }
                            else
                            {
                                roomTypes[roomCount] = 2;
                            }
                            roomCount++;

                            printf("Room added successfully.\n");
                            break;

                        case 2:
                            if (roomCount == 0)
                            {
                                printf("No room records available.\n");
                            }
                            else
                            {
                                printf("\nRoom Records\n");
                                printf("----------------------------------------\n");
                                for (i = 0; i < roomCount; i++)
                                {
                                    available = roomCapacities[i] - roomOccupied[i];
                                    printf("Room: %d | Type: %s | Capacity: %d | Occupied: %d | Available: %d | Status: ",
                                           roomNumbers[i],
                                           roomTypes[i] == 1 ? "Single" : "Double",
                                           roomCapacities[i], roomOccupied[i], available);
                                    if (available > 0)
                                    {
                                        printf("AVAILABLE\n");
                                    }
                                    else
                                    {
                                        printf("FULL\n");
                                    }
                                }
                            }
                            break;

                        case 3:
                            if (studentCount == 0 || roomCount == 0)
                            {
                                printf("Register a student and add a room first.\n");
                                break;
                            }

                            printf("Enter Student ID: ");
                            validInput = scanf("%d", &id);
                            if (validInput != 1)
                            {
                                printf("Invalid Student ID.\n");
                                while (getchar() != '\n');
                                break;
                            }

                            found = -1;
                            for (i = 0; i < studentCount; i++)
                            {
                                if (studentIDs[i] == id)
                                {
                                    found = i;
                                }
                            }

                            if (found == -1)
                            {
                                printf("Student ID not found.\n");
                                break;
                            }
                            if (studentRooms[found] != 0)
                            {
                                printf("This student already has a room allocated.\n");
                                break;
                            }

                            printf("Available rooms:\n");
                            for (i = 0; i < roomCount; i++)
                            {
                                if (roomOccupied[i] < roomCapacities[i])
                                {
                                    printf("Room %d: %d spaces available\n",
                                           roomNumbers[i],
                                           roomCapacities[i] - roomOccupied[i]);
                                }
                            }

                            printf("Enter Room Number to allocate: ");
                            validInput = scanf("%d", &roomNo);
                            if (validInput != 1)
                            {
                                printf("Invalid room number.\n");
                                while (getchar() != '\n');
                                break;
                            }

                            selectedRoom = -1;
                            for (i = 0; i < roomCount; i++)
                            {
                                if (roomNumbers[i] == roomNo)
                                {
                                    selectedRoom = i;
                                }
                            }

                            if (selectedRoom == -1)
                            {
                                printf("Room not found.\n");
                            }
                            else if (roomOccupied[selectedRoom] >= roomCapacities[selectedRoom])
                            {
                                printf("Room is full.\n");
                            }
                            else
                            {
                                roomOccupied[selectedRoom]++;
                                studentRooms[found] = roomNo;
                                printf("Room allocated successfully.\n");
                                printf("Student ID: %d | Room: %d | Vacancy left: %d\n",
                                       id, roomNo,
                                       roomCapacities[selectedRoom] - roomOccupied[selectedRoom]);
                            }
                            break;

                        case 4:
                            printf("Returning to main menu.\n");
                            break;
                    }
                } while (subChoice != 4);
                break;

            case 3:
                do
                {
                    printf("\n========== FEE MANAGEMENT ==========\n");
                    printf("1. Add / Update Student Fee\n");
                    printf("2. Display Fee Records\n");
                    printf("3. Back to Main Menu\n");

                    do
                    {
                        printf("Enter choice (1-3): ");
                        validInput = scanf("%d", &subChoice);
                        if (validInput != 1)
                        {
                            printf("Please enter a number.\n");
                            while (getchar() != '\n');
                            subChoice = 0;
                        }
                        else if (subChoice < 1 || subChoice > 3)
                        {
                            printf("Invalid choice. Try again.\n");
                        }
                    } while (subChoice < 1 || subChoice > 3);

                    switch (subChoice)
                    {
                        case 1:
                            if (studentCount == 0)
                            {
                                printf("Register a student first.\n");
                                break;
                            }

                            printf("Enter Student ID: ");
                            validInput = scanf("%d", &id);
                            if (validInput != 1)
                            {
                                printf("Invalid Student ID.\n");
                                while (getchar() != '\n');
                                break;
                            }

                            found = -1;
                            for (i = 0; i < studentCount; i++)
                            {
                                if (studentIDs[i] == id)
                                {
                                    found = i;
                                }
                            }
                            if (found == -1)
                            {
                                printf("Student ID not found.\n");
                                break;
                            }

                            j = -1;
                            for (i = 0; i < feeCount; i++)
                            {
                                if (feeStudentIDs[i] == id)
                                {
                                    j = i;
                                }
                            }

                            if (j == -1 && feeCount == 50)
                            {
                                printf("Fee record list is full.\n");
                                break;
                            }

                            do
                            {
                                printf("Enter Total Fee: ");
                                validInput = scanf("%f", &total);
                                if (validInput != 1)
                                {
                                    printf("Enter a valid amount.\n");
                                    while (getchar() != '\n');
                                    total = 0;
                                }
                                else if (total <= 0)
                                {
                                    printf("Total fee must be greater than zero.\n");
                                }
                            } while (total <= 0);

                            do
                            {
                                printf("Enter Paid Amount: ");
                                validInput = scanf("%f", &paid);
                                if (validInput != 1)
                                {
                                    printf("Enter a valid amount.\n");
                                    while (getchar() != '\n');
                                    paid = -1;
                                }
                                else if (paid < 0 || paid > total)
                                {
                                    printf("Paid amount must be between zero and total fee.\n");
                                }
                            } while (paid < 0 || paid > total);

                            if (j == -1)
                            {
                                j = feeCount;
                                feeStudentIDs[j] = id;
                                feeCount++;
                            }
                            totalFees[j] = total;
                            paidFees[j] = paid;
                            printf("Fee record saved.\n");
                            printf("Total: %.2f | Paid: %.2f | Remaining: %.2f\n",
                                   totalFees[j], paidFees[j], totalFees[j] - paidFees[j]);
                            if (totalFees[j] == paidFees[j])
                            {
                                printf("Status: PAID\n");
                            }
                            else
                            {
                                printf("Status: DUE\n");
                            }
                            break;

                        case 2:
                            if (feeCount == 0)
                            {
                                printf("No fee records available.\n");
                            }
                            else
                            {
                                for (i = 0; i < feeCount; i++)
                                {
                                    printf("Student ID: %d | Total: %.2f | Paid: %.2f | Remaining: %.2f | Status: %s\n",
                                           feeStudentIDs[i], totalFees[i], paidFees[i],
                                           totalFees[i] - paidFees[i],
                                           totalFees[i] == paidFees[i] ? "PAID" : "DUE");
                                }
                            }
                            break;

                        case 3:
                            printf("Returning to main menu.\n");
                            break;
                    }
                } while (subChoice != 3);
                break;

            case 4:
                do
                {
                    printf("\n========== COMPLAINT MANAGEMENT ==========\n");
                    printf("1. Submit Complaint\n");
                    printf("2. Check Complaint Status\n");
                    printf("3. Update Complaint Status\n");
                    printf("4. Back to Main Menu\n");

                    do
                    {
                        printf("Enter choice (1-4): ");
                        validInput = scanf("%d", &subChoice);
                        if (validInput != 1)
                        {
                            printf("Please enter a number.\n");
                            while (getchar() != '\n');
                            subChoice = 0;
                        }
                        else if (subChoice < 1 || subChoice > 4)
                        {
                            printf("Invalid choice. Try again.\n");
                        }
                    } while (subChoice < 1 || subChoice > 4);

                    switch (subChoice)
                    {
                        case 1:
                            if (complaintCount == 50)
                            {
                                printf("Complaint list is full.\n");
                                break;
                            }
                            if (studentCount == 0)
                            {
                                printf("Register a student first.\n");
                                break;
                            }

                            printf("Enter Student ID: ");
                            validInput = scanf("%d", &complaintStudent);
                            if (validInput != 1)
                            {
                                printf("Invalid Student ID.\n");
                                while (getchar() != '\n');
                                break;
                            }

                            found = 0;
                            for (i = 0; i < studentCount; i++)
                            {
                                if (studentIDs[i] == complaintStudent)
                                {
                                    found = 1;
                                }
                            }
                            if (!found)
                            {
                                printf("Student ID not found.\n");
                                break;
                            }

                            do
                            {
                                printf("Enter Complaint ID: ");
                                validInput = scanf("%d", &complaintNo);
                                if (validInput != 1)
                                {
                                    printf("Complaint ID must be numeric.\n");
                                    while (getchar() != '\n');
                                    complaintNo = 0;
                                }
                                else if (complaintNo <= 0)
                                {
                                    printf("Complaint ID must be greater than zero.\n");
                                }
                                else
                                {
                                    found = 0;
                                    for (i = 0; i < complaintCount; i++)
                                    {
                                        if (complaintIDs[i] == complaintNo)
                                        {
                                            found = 1;
                                        }
                                    }
                                    if (found)
                                    {
                                        printf("Complaint ID already exists.\n");
                                        complaintNo = 0;
                                    }
                                }
                            } while (complaintNo <= 0);

                            complaintIDs[complaintCount] = complaintNo;
                            complaintStudentIDs[complaintCount] = complaintStudent;
                            complaintStatus[complaintCount] = 0;
                            complaintCount++;
                            printf("Complaint submitted. Status: PENDING\n");
                            break;

                        case 2:
                            printf("Enter Complaint ID: ");
                            validInput = scanf("%d", &complaintNo);
                            if (validInput != 1)
                            {
                                printf("Invalid Complaint ID.\n");
                                while (getchar() != '\n');
                                break;
                            }

                            found = -1;
                            for (i = 0; i < complaintCount; i++)
                            {
                                if (complaintIDs[i] == complaintNo)
                                {
                                    found = i;
                                }
                            }
                            if (found == -1)
                            {
                                printf("Complaint not found.\n");
                            }
                            else
                            {
                                printf("Complaint ID: %d | Student ID: %d | Status: %s\n",
                                       complaintIDs[found], complaintStudentIDs[found],
                                       complaintStatus[found] == 0 ? "PENDING" :
                                       complaintStatus[found] == 1 ? "UNDER REVIEW" : "RESOLVED");
                            }
                            break;

                        case 3:
                            printf("Enter Complaint ID: ");
                            validInput = scanf("%d", &complaintNo);
                            if (validInput != 1)
                            {
                                printf("Invalid Complaint ID.\n");
                                while (getchar() != '\n');
                                break;
                            }

                            found = -1;
                            for (i = 0; i < complaintCount; i++)
                            {
                                if (complaintIDs[i] == complaintNo)
                                {
                                    found = i;
                                }
                            }
                            if (found == -1)
                            {
                                printf("Complaint not found.\n");
                                break;
                            }

                            printf("1. Pending\n2. Under Review\n3. Resolved\n");
                            do
                            {
                                printf("Select new status (1-3): ");
                                validInput = scanf("%d", &statusChoice);
                                if (validInput != 1)
                                {
                                    printf("Enter a number from 1 to 3.\n");
                                    while (getchar() != '\n');
                                    statusChoice = 0;
                                }
                                else if (statusChoice < 1 || statusChoice > 3)
                                {
                                    printf("Enter a number from 1 to 3.\n");
                                }
                            } while (statusChoice < 1 || statusChoice > 3);

                            complaintStatus[found] = statusChoice - 1;
                            printf("Complaint status updated.\n");
                            break;

                        case 4:
                            printf("Returning to main menu.\n");
                            break;
                    }
                } while (subChoice != 4);
                break;

            case 5:
                printf("\n========== HOSTEL INFORMATION ==========\n");
                printf("Hostel Name: University Hostel\n");
                printf("Hostel Type: Student Residence\n");
                printf("Facilities: Study Area, Security, Common Room, Washrooms\n");
                printf("Maximum student records: 50\n");
                printf("Maximum room records: 30\n");
                printf("Room vacancy is updated automatically after allocation.\n");
                break;

            case 6:
                do
                {
                    printf("\n========== SEARCH / REPORTS ==========\n");
                    printf("1. Student Count and Records\n");
                    printf("2. Room Occupancy Report\n");
                    printf("3. Fee Summary\n");
                    printf("4. Complaint Summary\n");
                    printf("5. Back to Main Menu\n");

                    do
                    {
                        printf("Enter choice (1-5): ");
                        validInput = scanf("%d", &subChoice);
                        if (validInput != 1)
                        {
                            printf("Please enter a number.\n");
                            while (getchar() != '\n');
                            subChoice = 0;
                        }
                        else if (subChoice < 1 || subChoice > 5)
                        {
                            printf("Invalid choice. Try again.\n");
                        }
                    } while (subChoice < 1 || subChoice > 5);

                    switch (subChoice)
                    {
                        case 1:
                            printf("Total registered students: %d\n", studentCount);
                            for (i = 0; i < studentCount; i++)
                            {
                                printf("ID: %d | Age: %d | Room: ",
                                       studentIDs[i], studentAges[i]);
                                if (studentRooms[i] == 0)
                                {
                                    printf("Not allocated\n");
                                }
                                else
                                {
                                    printf("%d\n", studentRooms[i]);
                                }
                            }
                            break;

                        case 2:
                            printf("Total rooms: %d\n", roomCount);
                            for (i = 0; i < roomCount; i++)
                            {
                                printf("Room %d | Capacity: %d | Occupied: %d | Vacant: %d\n",
                                       roomNumbers[i], roomCapacities[i],
                                       roomOccupied[i],
                                       roomCapacities[i] - roomOccupied[i]);
                            }
                            break;

                        case 3:
                            total = 0;
                            paid = 0;
                            for (i = 0; i < feeCount; i++)
                            {
                                total += totalFees[i];
                                paid += paidFees[i];
                            }
                            printf("Fee records: %d\n", feeCount);
                            printf("Total billed: %.2f\n", total);
                            printf("Total paid: %.2f\n", paid);
                            printf("Total outstanding: %.2f\n", total - paid);
                            break;

                        case 4:
                            printf("Total complaints: %d\n", complaintCount);
                            for (i = 0; i < complaintCount; i++)
                            {
                                printf("Complaint ID: %d | Student ID: %d | Status: %s\n",
                                       complaintIDs[i], complaintStudentIDs[i],
                                       complaintStatus[i] == 0 ? "PENDING" :
                                       complaintStatus[i] == 1 ? "UNDER REVIEW" : "RESOLVED");
                            }
                            break;

                        case 5:
                            printf("Returning to main menu.\n");
                            break;
                    }
                } while (subChoice != 5);
                break;

            case 7:
                printf("Thank you for using Hostel Management System.\n");
                break;
        }
    } while (mainChoice != 7);

    return 0;
}
