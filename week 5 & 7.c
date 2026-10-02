#include <stdio.h>

int main()
{
    /* ================= STUDENT VARIABLES ================= */

    int studentID;
    int enteredID;
    int age;
    char studentName[50];
    char password[30];
    char enteredPassword[30];

    /* ================= ROOM VARIABLES ================= */

    int roomNumber;
    int capacity;
    int occupied;
    int available;
    char roomType;

    /* ================= FEE VARIABLES ================= */

    float totalFee;
    float paidFee;
    float remainingFee;

    /* ================= COMPLAINT VARIABLES ================= */

    int complaintID;

    /* ================= MENU VARIABLES ================= */

    int mainChoice;
    int subChoice;


    /* ================= PROGRAM HEADER ================= */

    printf("========================================\n");
    printf("       HOSTEL MANAGEMENT SYSTEM\n");
    printf("========================================\n");


    /* =====================================================
       WEEK 7:
       Main menu repeats until user selects Exit.
       ===================================================== */

    do
    {
        printf("\n\n========== MAIN MENU ==========\n");
        printf("1. Student Management\n");
        printf("2. Room Management\n");
        printf("3. Fee Management\n");
        printf("4. Complaint Management\n");
        printf("5. Hostel Information\n");
        printf("6. Search / Reports\n");
        printf("7. Exit\n");


        /* Main menu validation */

        do
        {
            printf("\nEnter your choice (1-7): ");
            scanf("%d", &mainChoice);

            if (mainChoice < 1 || mainChoice > 7)
            {
                printf("Invalid choice. Please enter a number from 1 to 7.\n");
            }

        } while (mainChoice < 1 || mainChoice > 7);


        /* =====================================================
           MAIN SWITCH
           ===================================================== */

        switch (mainChoice)
        {

            /* =================================================
               1. STUDENT MANAGEMENT
               Ameet Kumar
               ================================================= */

            case 1:

                printf("\n========== STUDENT MANAGEMENT ==========\n");
                printf("1. Student Registration\n");
                printf("2. Student Login\n");
                printf("3. Display Student Information\n");


                do
                {
                    printf("\nEnter choice (1-3): ");
                    scanf("%d", &subChoice);

                    if (subChoice < 1 || subChoice > 3)
                    {
                        printf("Invalid choice. Please try again.\n");
                    }

                } while (subChoice < 1 || subChoice > 3);


                /* Nested switch */

                switch (subChoice)
                {

                    /* ---------- STUDENT REGISTRATION ---------- */

                    case 1:

                        printf("\n---------- Student Registration ----------\n");


                        do
                        {
                            printf("Enter Student ID: ");
                            scanf("%d", &studentID);

                            if (studentID <= 0)
                            {
                                printf("Invalid Student ID. Please try again.\n");
                            }

                        } while (studentID <= 0);


                        printf("Enter Student Name: ");
                        scanf(" %[^\n]", studentName);


                        do
                        {
                            printf("Enter Age: ");
                            scanf("%d", &age);

                            if (age < 16 || age > 40)
                            {
                                printf("Invalid Age. Age must be between 16 and 40.\n");
                            }

                        } while (age < 16 || age > 40);


                        do
                        {
                            printf("Create Password: ");
                            scanf("%s", password);

                            if (password[0] == '\0')
                            {
                                printf("Password cannot be empty.\n");
                            }

                        } while (password[0] == '\0');


                        printf("\nRegistration Successful!\n");
                        printf("Student ID : %d\n", studentID);
                        printf("Name       : %s\n", studentName);
                        printf("Age        : %d\n", age);

                        break;


                    /* ---------- STUDENT LOGIN ---------- */

                    case 2:

                        printf("\n---------- Student Login ----------\n");


                        do
                        {
                            printf("Enter Student ID: ");
                            scanf("%d", &enteredID);

                            if (enteredID <= 0)
                            {
                                printf("Invalid Student ID. Please try again.\n");
                            }

                        } while (enteredID <= 0);


                        do
                        {
                            printf("Enter Password: ");
                            scanf("%s", enteredPassword);

                            if (enteredPassword[0] == '\0')
                            {
                                printf("Password cannot be empty.\n");
                            }

                        } while (enteredPassword[0] == '\0');


                        if (enteredID > 0 && enteredPassword[0] != '\0')
                        {
                            printf("\nLogin Successful!\n");
                            printf("Welcome to Hostel Management System.\n");
                        }
                        else
                        {
                            printf("\nLogin Failed.\n");
                        }

                        break;


                    /* ---------- STUDENT INFORMATION ---------- */

                    case 3:

                        printf("\n---------- Student Information ----------\n");


                        do
                        {
                            printf("Enter Student ID: ");
                            scanf("%d", &studentID);

                            if (studentID <= 0)
                            {
                                printf("Invalid Student ID. Please try again.\n");
                            }

                        } while (studentID <= 0);


                        printf("Enter Student Name: ");
                        scanf(" %[^\n]", studentName);


                        do
                        {
                            printf("Enter Age: ");
                            scanf("%d", &age);

                            if (age < 16 || age > 40)
                            {
                                printf("Invalid Age. Please try again.\n");
                            }

                        } while (age < 16 || age > 40);


                        printf("\nStudent Information\n");
                        printf("---------------------------\n");
                        printf("Student ID : %d\n", studentID);
                        printf("Name       : %s\n", studentName);
                        printf("Age        : %d\n", age);

                        break;
                }

                break;


            /* =================================================
               2. ROOM MANAGEMENT
               Mujtaba Ahmed
               ================================================= */

            case 2:

                printf("\n========== ROOM MANAGEMENT ==========\n");
                printf("1. View Room Information\n");
                printf("2. Check Room Availability\n");
                printf("3. Allocate Room\n");


                do
                {
                    printf("\nEnter choice (1-3): ");
                    scanf("%d", &subChoice);

                    if (subChoice < 1 || subChoice > 3)
                    {
                        printf("Invalid choice. Please try again.\n");
                    }

                } while (subChoice < 1 || subChoice > 3);


                switch (subChoice)
                {

                    /* ---------- ROOM INFORMATION ---------- */

                    case 1:

                        printf("\n---------- Room Information ----------\n");


                        do
                        {
                            printf("Enter Room Number: ");
                            scanf("%d", &roomNumber);

                            if (roomNumber <= 0)
                            {
                                printf("Invalid Room Number. Please try again.\n");
                            }

                        } while (roomNumber <= 0);


                        do
                        {
                            printf("Enter Room Type (S = Single, D = Double): ");
                            scanf(" %c", &roomType);

                            if (roomType != 'S' &&
                                roomType != 's' &&
                                roomType != 'D' &&
                                roomType != 'd')
                            {
                                printf("Invalid Room Type. Please try again.\n");
                            }

                        } while (roomType != 'S' &&
                                 roomType != 's' &&
                                 roomType != 'D' &&
                                 roomType != 'd');


                        do
                        {
                            printf("Enter Room Capacity: ");
                            scanf("%d", &capacity);

                            if (capacity <= 0)
                            {
                                printf("Invalid Capacity. Please try again.\n");
                            }

                        } while (capacity <= 0);


                        if (roomType == 'S' || roomType == 's')
                        {
                            printf("\nRoom Type: Single Room\n");
                        }
                        else
                        {
                            printf("\nRoom Type: Double Room\n");
                        }


                        printf("Room Number: %d\n", roomNumber);
                        printf("Capacity   : %d\n", capacity);

                        break;


                    /* ---------- ROOM AVAILABILITY ---------- */

                    case 2:

                        printf("\n---------- Check Room Availability ----------\n");


                        do
                        {
                            printf("Enter Room Number: ");
                            scanf("%d", &roomNumber);

                            if (roomNumber <= 0)
                            {
                                printf("Invalid Room Number. Please try again.\n");
                            }

                        } while (roomNumber <= 0);


                        do
                        {
                            printf("Enter Room Capacity: ");
                            scanf("%d", &capacity);

                            if (capacity <= 0)
                            {
                                printf("Invalid Capacity. Please try again.\n");
                            }

                        } while (capacity <= 0);


                        do
                        {
                            printf("Enter Current Occupancy: ");
                            scanf("%d", &occupied);

                            if (occupied < 0 || occupied > capacity)
                            {
                                printf("Invalid Occupancy. Please try again.\n");
                            }

                        } while (occupied < 0 || occupied > capacity);


                        available = capacity - occupied;


                        printf("\nAvailable Spaces: %d\n", available);


                        if (available > 0)
                        {
                            printf("Room Status: AVAILABLE\n");
                        }
                        else
                        {
                            printf("Room Status: FULL\n");
                        }

                        break;


                    /* ---------- ROOM ALLOCATION ---------- */

                    case 3:

                        printf("\n---------- Room Allocation ----------\n");


                        do
                        {
                            printf("Enter Room Number: ");
                            scanf("%d", &roomNumber);

                            if (roomNumber <= 0)
                            {
                                printf("Invalid Room Number. Please try again.\n");
                            }

                        } while (roomNumber <= 0);


                        do
                        {
                            printf("Enter Room Capacity: ");
                            scanf("%d", &capacity);

                            if (capacity <= 0)
                            {
                                printf("Invalid Capacity. Please try again.\n");
                            }

                        } while (capacity <= 0);


                        do
                        {
                            printf("Enter Current Occupancy: ");
                            scanf("%d", &occupied);

                            if (occupied < 0 || occupied > capacity)
                            {
                                printf("Invalid Occupancy. Please try again.\n");
                            }

                        } while (occupied < 0 || occupied > capacity);


                        if (occupied < capacity)
                        {
                            available = capacity - occupied;

                            printf("\nRoom is AVAILABLE.\n");
                            printf("Available Spaces: %d\n", available);


                            occupied = occupied + 1;


                            printf("\nAllocation Successful!\n");
                            printf("New Occupancy: %d\n", occupied);
                            printf("Remaining Vacancy: %d\n",
                                   capacity - occupied);
                        }
                        else
                        {
                            printf("\nRoom is FULL.\n");
                            printf("Allocation cannot be completed.\n");
                        }

                        break;
                }

                break;


            /* =================================================
               3. FEE MANAGEMENT
               Dilshan
               ================================================= */

            case 3:

                do
                {
                    printf("\n========== FEE MANAGEMENT ==========\n");
                    printf("1. Calculate Remaining Fee\n");
                    printf("2. Check Fee Status\n");
                    printf("3. Back to Main Menu\n");


                    do
                    {
                        printf("\nEnter choice (1-3): ");
                        scanf("%d", &subChoice);

                        if (subChoice < 1 || subChoice > 3)
                        {
                            printf("Invalid choice. Please try again.\n");
                        }

                    } while (subChoice < 1 || subChoice > 3);


                    switch (subChoice)
                    {

                        /* ---------- CALCULATE FEE ---------- */

                        case 1:

                            printf("\n---------- Fee Calculation ----------\n");


                            do
                            {
                                printf("Enter Total Fee: ");
                                scanf("%f", &totalFee);

                                if (totalFee <= 0)
                                {
                                    printf("Invalid Total Fee. Please try again.\n");
                                }

                            } while (totalFee <= 0);


                            do
                            {
                                printf("Enter Paid Amount: ");
                                scanf("%f", &paidFee);

                                if (paidFee < 0 || paidFee > totalFee)
                                {
                                    printf("Invalid Paid Amount.\n");
                                    printf("Paid amount cannot be greater than total fee.\n");
                                }

                            } while (paidFee < 0 || paidFee > totalFee);


                            remainingFee = totalFee - paidFee;


                            printf("\nTotal Fee      : %.2f\n", totalFee);
                            printf("Paid Amount    : %.2f\n", paidFee);
                            printf("Remaining Fee  : %.2f\n",
                                   remainingFee);


                            if (remainingFee == 0)
                            {
                                printf("Status         : PAID\n");
                            }
                            else
                            {
                                printf("Status         : DUE\n");
                            }

                            break;


                        /* ---------- FEE STATUS ---------- */

                        case 2:

                            printf("\n---------- Fee Status ----------\n");


                            do
                            {
                                printf("Enter Total Fee: ");
                                scanf("%f", &totalFee);

                                if (totalFee <= 0)
                                {
                                    printf("Invalid Total Fee. Please try again.\n");
                                }

                            } while (totalFee <= 0);


                            do
                            {
                                printf("Enter Paid Amount: ");
                                scanf("%f", &paidFee);

                                if (paidFee < 0 || paidFee > totalFee)
                                {
                                    printf("Invalid Paid Amount.\n");
                                }

                            } while (paidFee < 0 || paidFee > totalFee);


                            remainingFee = totalFee - paidFee;


                            if (remainingFee == 0)
                            {
                                printf("\nFee Status: PAID\n");
                            }
                            else
                            {
                                printf("\nFee Status: DUE\n");
                                printf("Amount Due: %.2f\n",
                                       remainingFee);
                            }

                            break;


                        /* ---------- BACK ---------- */

                        case 3:

                            printf("\nReturning to Main Menu...\n");

                            break;
                    }

                } while (subChoice != 3);

                break;


            /* =================================================
               4. COMPLAINT MANAGEMENT
               Dilshan
               ================================================= */

            case 4:

                do
                {
                    printf("\n========== COMPLAINT MANAGEMENT ==========\n");
                    printf("1. Submit Complaint\n");
                    printf("2. Check Complaint Status\n");
                    printf("3. Back to Main Menu\n");


                    do
                    {
                        printf("\nEnter choice (1-3): ");
                        scanf("%d", &subChoice);

                        if (subChoice < 1 || subChoice > 3)
                        {
                            printf("Invalid choice. Please try again.\n");
                        }

                    } while (subChoice < 1 || subChoice > 3);


                    switch (subChoice)
                    {

                        /* ---------- SUBMIT COMPLAINT ---------- */

                        case 1:

                            printf("\n---------- Submit Complaint ----------\n");


                            do
                            {
                                printf("Enter Complaint ID: ");
                                scanf("%d", &complaintID);

                                if (complaintID <= 0)
                                {
                                    printf("Invalid Complaint ID. Please try again.\n");
                                }

                            } while (complaintID <= 0);


                            printf("\nComplaint registered successfully.\n");
                            printf("Complaint ID: %d\n",
                                   complaintID);
                            printf("Status: PENDING\n");

                            break;


                        /* ---------- CHECK COMPLAINT ---------- */

                        case 2:

                            printf("\n---------- Complaint Status ----------\n");


                            do
                            {
                                printf("Enter Complaint ID: ");
                                scanf("%d", &complaintID);

                                if (complaintID <= 0)
                                {
                                    printf("Invalid Complaint ID. Please try again.\n");
                                }

                            } while (complaintID <= 0);


                            printf("\nComplaint ID: %d\n",
                                   complaintID);
                            printf("Status: UNDER REVIEW\n");

                            break;


                        /* ---------- BACK ---------- */

                        case 3:

                            printf("\nReturning to Main Menu...\n");

                            break;
                    }

                } while (subChoice != 3);

                break;


            /* =================================================
               5. HOSTEL INFORMATION
               Mujtaba
               ================================================= */

            case 5:

                printf("\n========== HOSTEL INFORMATION ==========\n");

                printf("Hostel Name : University Hostel\n");
                printf("Hostel Type : Student Residence\n");

                printf("\nFacilities:\n");
                printf("- Study Area\n");
                printf("- Security\n");
                printf("- Common Room\n");
                printf("- Washroom Facilities\n");
                printf("- Room Allocation System\n");

                break;


            /* =================================================
               6. SEARCH / REPORTS
               Shared
               ================================================= */

            case 6:

                printf("\n========== SEARCH / REPORTS ==========\n");
                printf("1. Student Search\n");
                printf("2. Room Report\n");
                printf("3. Fee Report\n");
                printf("4. Complaint Report\n");


                do
                {
                    printf("\nEnter choice (1-4): ");
                    scanf("%d", &subChoice);

                    if (subChoice < 1 || subChoice > 4)
                    {
                        printf("Invalid choice. Please try again.\n");
                    }

                } while (subChoice < 1 || subChoice > 4);


                switch (subChoice)
                {

                    /* ---------- STUDENT SEARCH ---------- */

                    case 1:

                        printf("\n---------- Student Search ----------\n");


                        do
                        {
                            printf("Enter Student ID: ");
                            scanf("%d", &studentID);

                            if (studentID <= 0)
                            {
                                printf("Invalid Student ID. Please try again.\n");
                            }

                        } while (studentID <= 0);


                        printf("Student ID: %d\n", studentID);
                        printf("Student search operation completed.\n");

                        break;


                    /* ---------- ROOM REPORT ---------- */

                    case 2:

                        printf("\n---------- Room Report ----------\n");


                        do
                        {
                            printf("Enter Room Number: ");
                            scanf("%d", &roomNumber);

                            if (roomNumber <= 0)
                            {
                                printf("Invalid Room Number. Please try again.\n");
                            }

                        } while (roomNumber <= 0);


                        printf("Room Number: %d\n", roomNumber);
                        printf("Room report generated.\n");

                        break;


                    /* ---------- FEE REPORT ---------- */

                    case 3:

                        printf("\n---------- Fee Report ----------\n");


                        do
                        {
                            printf("Enter Total Fee: ");
                            scanf("%f", &totalFee);

                            if (totalFee <= 0)
                            {
                                printf("Invalid Total Fee. Please try again.\n");
                            }

                        } while (totalFee <= 0);


                        do
                        {
                            printf("Enter Paid Amount: ");
                            scanf("%f", &paidFee);

                            if (paidFee < 0 || paidFee > totalFee)
                            {
                                printf("Invalid Paid Amount. Please try again.\n");
                            }

                        } while (paidFee < 0 || paidFee > totalFee);


                        remainingFee = totalFee - paidFee;


                        printf("\nTotal Fee      : %.2f\n",
                               totalFee);
                        printf("Paid Amount    : %.2f\n",
                               paidFee);
                        printf("Remaining Fee  : %.2f\n",
                               remainingFee);


                        if (remainingFee == 0)
                        {
                            printf("Fee Status     : PAID\n");
                        }
                        else
                        {
                            printf("Fee Status     : DUE\n");
                        }

                        break;


                    /* ---------- COMPLAINT REPORT ---------- */

                    case 4:

                        printf("\n---------- Complaint Report ----------\n");


                        do
                        {
                            printf("Enter Complaint ID: ");
                            scanf("%d", &complaintID);

                            if (complaintID <= 0)
                            {
                                printf("Invalid Complaint ID. Please try again.\n");
                            }

                        } while (complaintID <= 0);


                        printf("Complaint ID     : %d\n",
                               complaintID);
                        printf("Complaint Status : UNDER REVIEW\n");

                        break;
                }

                break;


            /* =================================================
               7. EXIT
               ================================================= */

            case 7:

                printf("\n========================================\n");
                printf("Thank you for using the Hostel\n");
                printf("Management System.\n");
                printf("Program Exited Successfully.\n");
                printf("========================================\n");

                break;
        }

    } while (mainChoice != 7);


    return 0;
}