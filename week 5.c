#include <stdio.h>

int main() {

    int studentID;
    int enteredID;
    int age;

    char studentName[50];
    char password[30];
    char enteredPassword[30];

    int roomNumber;
    int capacity;
    int occupied;
    int available;

    char roomType;

    float totalFee;
    float paidFee;
    float remainingFee;

    int complaintID;

    int mainChoice;
    int subChoice;

    printf("HOSTEL MANAGEMENT SYSTEM\n");

    printf("\n1. Student Management\n");
    printf("2. Room Management\n");
    printf("3. Fee Management\n");
    printf("4. Complaint Management\n");
    printf("5. Hostel Information\n");
    printf("6. Search / Reports\n");
    printf("7. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &mainChoice);

    switch (mainChoice) {

        case 1:

            printf("          STUDENT MANAGEMENT\n");

            printf("1. Student Registration\n");
            printf("2. Student Login\n");
            printf("3. Display Student Information\n");

            printf("\nEnter choice: ");
            scanf("%d", &subChoice);

            switch (subChoice) {

                case 1:

                    printf("\n Student Registration \n");

                    printf("Enter Student ID: ");
                    scanf("%d", &studentID);

                    printf("Enter Student Name: ");
                    scanf(" %[^\n]", studentName);

                    printf("Enter Age: ");
                    scanf("%d", &age);

                    printf("Create Password: ");
                    scanf("%s", password);

                    if (studentID > 0 &&
                        age >= 16 &&
                        age <= 40) {

                        printf("\nRegistration Successful!\n");
                        printf("Student ID : %d\n", studentID);
                        printf("Name       : %s\n", studentName);
                        printf("Age        : %d\n", age);

                    } else {

                        printf("\nRegistration Failed!\n");

                        if (studentID <= 0) {
                            printf("Invalid Student ID.\n");
                        }

                        if (age < 16 || age > 40) {
                            printf("Invalid Age.\n");
                        }
                    }

                    break;

                case 2:

                    printf("\n Student Login \n");

                    printf("Enter Student ID: ");
                    scanf("%d", &enteredID);

                    printf("Enter Password: ");
                    scanf("%s", enteredPassword);

                    if (enteredID > 0 &&
                        enteredPassword[0] != '\0') {

                        printf("\nLogin Successful!\n");
                        printf("Welcome to Hostel Management System.\n");

                    } else {

                        printf("\nLogin Failed!\n");
                        printf("Invalid Student ID or Password.\n");
                    }

                    break;

                case 3:

                    printf("\n Student Information \n");

                    printf("Enter Student ID: ");
                    scanf("%d", &studentID);

                    printf("Enter Student Name: ");
                    scanf(" %[^\n]", studentName);

                    printf("Enter Age: ");
                    scanf("%d", &age);

                    if (studentID > 0) {

                        printf("\nStudent Information\n");
                        printf("Student ID : %d\n", studentID);
                        printf("Name       : %s\n", studentName);
                        printf("Age        : %d\n", age);

                    } else {

                        printf("\nInvalid Student ID.\n");
                    }

                    break;

                default:

                    printf("\nInvalid Student Management choice.\n");
            }

            break;

        case 2:

            printf("           ROOM MANAGEMENT\n");

            printf("1. View Room Information\n");
            printf("2. Check Room Availability\n");
            printf("3. Allocate Room\n");

            printf("\nEnter choice: ");
            scanf("%d", &subChoice);

            switch (subChoice) {

                case 1:

                    printf("\n Room Information \n");

                    printf("Enter Room Number: ");
                    scanf("%d", &roomNumber);

                    printf("Enter Room Type (S = Single, D = Double): ");
                    scanf(" %c", &roomType);

                    printf("Enter Room Capacity: ");
                    scanf("%d", &capacity);

                    if (roomType == 'S' || roomType == 's') {

                        printf("\nRoom Type: Single Room\n");

                    } else if (roomType == 'D' || roomType == 'd') {

                        printf("\nRoom Type: Double Room\n");

                    } else {

                        printf("\nInvalid Room Type.\n");
                    }

                    if (roomNumber > 0 && capacity > 0) {

                        printf("Room Number: %d\n", roomNumber);
                        printf("Capacity   : %d\n", capacity);

                    } else {

                        printf("Invalid room information.\n");
                    }

                    break;

                case 2:

                    printf("\n Check Room Availability \n");

                    printf("Enter Room Number: ");
                    scanf("%d", &roomNumber);

                    printf("Enter Room Capacity: ");
                    scanf("%d", &capacity);

                    printf("Enter Current Occupancy: ");
                    scanf("%d", &occupied);

                    if (roomNumber > 0 &&
                        capacity > 0 &&
                        occupied >= 0 &&
                        occupied <= capacity) {

                        available = capacity - occupied;

                        printf("\nAvailable Spaces: %d\n", available);

                        if (available > 0) {

                            printf("Room Status: AVAILABLE\n");

                        } else {

                            printf("Room Status: FULL\n");
                        }

                    } else {

                        printf("\nInvalid room information.\n");
                    }

                    break;

                case 3:

                    printf("\n Room Allocation \n");

                    printf("Enter Room Number: ");
                    scanf("%d", &roomNumber);

                    printf("Enter Room Capacity: ");
                    scanf("%d", &capacity);

                    printf("Enter Current Occupancy: ");
                    scanf("%d", &occupied);

                    if (roomNumber > 0 &&
                        capacity > 0 &&
                        occupied >= 0 &&
                        occupied < capacity) {

                        available = capacity - occupied;

                        printf("\nRoom is AVAILABLE.\n");
                        printf("Available Spaces: %d\n", available);

                        occupied = occupied + 1;

                        printf("\nAllocation Successful!\n");
                        printf("New Occupancy: %d\n", occupied);
                        printf("Remaining Vacancy: %d\n",
                               capacity - occupied);

                    } else if (occupied == capacity) {

                        printf("\nRoom is FULL.\n");

                    } else {

                        printf("\nInvalid room information.\n");
                    }

                    break;

                default:

                    printf("\nInvalid Room Management choice.\n");
            }

            break;

        case 3:

            printf("            FEE MANAGEMENT\n");

            printf("1. Calculate Remaining Fee\n");
            printf("2. Check Fee Status\n");

            printf("\nEnter choice: ");
            scanf("%d", &subChoice);

            switch (subChoice) {

                case 1:

                    printf("\n Fee Calculation \n");

                    printf("Enter Total Fee: ");
                    scanf("%f", &totalFee);

                    printf("Enter Paid Amount: ");
                    scanf("%f", &paidFee);

                    if (totalFee >= 0 &&
                        paidFee >= 0 &&
                        paidFee <= totalFee) {

                        remainingFee = totalFee - paidFee;

                        printf("\nTotal Fee: %.2f\n", totalFee);
                        printf("Paid Amount: %.2f\n", paidFee);
                        printf("Remaining Fee: %.2f\n",
                               remainingFee);

                        if (remainingFee == 0) {

                            printf("Status: PAID\n");

                        } else {

                            printf("Status: DUE\n");
                        }

                    } else {

                        printf("\nInvalid fee information.\n");
                    }

                    break;

                case 2:

                    printf("\n Fee Status \n");

                    printf("Enter Total Fee: ");
                    scanf("%f", &totalFee);

                    printf("Enter Paid Amount: ");
                    scanf("%f", &paidFee);

                    if (totalFee > 0 && paidFee >= 0) {

                        remainingFee = totalFee - paidFee;

                        if (remainingFee <= 0) {

                            printf("\nFee Status: PAID\n");

                        } else {

                            printf("\nFee Status: DUE\n");
                            printf("Amount Due: %.2f\n",
                                   remainingFee);
                        }

                    } else {

                        printf("\nInvalid fee information.\n");
                    }

                    break;

                default:

                    printf("\nInvalid Fee choice.\n");
            }

            break;

        case 4:

            printf("        COMPLAINT MANAGEMENT\n");

            printf("1. Submit Complaint\n");
            printf("2. Check Complaint Status\n");

            printf("\nEnter choice: ");
            scanf("%d", &subChoice);

            switch (subChoice) {

                case 1:

                    printf("\n Submit Complaint \n");

                    printf("Enter Complaint ID: ");
                    scanf("%d", &complaintID);

                    if (complaintID > 0) {

                        printf("\nComplaint registered successfully.\n");
                        printf("Complaint ID: %d\n", complaintID);
                        printf("Status: PENDING\n");

                    } else {

                        printf("\nInvalid Complaint ID.\n");
                    }

                    break;

                case 2:

                    printf("\n--- Complaint Status ---\n");

                    printf("Enter Complaint ID: ");
                    scanf("%d", &complaintID);

                    if (complaintID > 0) {

                        printf("\nComplaint ID: %d\n", complaintID);
                        printf("Status: UNDER REVIEW\n");

                    } else {

                        printf("\nInvalid Complaint ID.\n");
                    }

                    break;

                default:

                    printf("\nInvalid Complaint choice.\n");
            }

            break;

        case 5:

            printf("          HOSTEL INFORMATION\n");

            printf("Hostel Name : University Hostel\n");
            printf("Hostel Type : Student Residence\n");
            printf("Facilities:\n");
            printf("- Study Area\n");
            printf("- Security\n");
            printf("- Common Room\n");
            printf("- Washroom Facilities\n");
            printf("- Room Allocation System\n");

            break;

        case 6:

            printf("           SEARCH / REPORTS\n");

            printf("1. Student Search\n");
            printf("2. Room Report\n");
            printf("3. Fee Report\n");
            printf("4. Complaint Report\n");

            printf("\nEnter choice: ");
            scanf("%d", &subChoice);

            switch (subChoice) {

                case 1:

                    printf("\n Student Search \n");

                    printf("Enter Student ID: ");
                    scanf("%d", &studentID);

                    if (studentID > 0) {

                        printf("Student ID: %d\n", studentID);
                        printf("Search operation completed.\n");

                    } else {

                        printf("Invalid Student ID.\n");
                    }

                    break;

                case 2:

                    printf("\n Room Report \n");

                    printf("Enter Room Number: ");
                    scanf("%d", &roomNumber);

                    if (roomNumber > 0) {

                        printf("Room Number: %d\n", roomNumber);
                        printf("Room report generated.\n");

                    } else {

                        printf("Invalid Room Number.\n");
                    }

                    break;

                case 3:

                    printf("\n Fee Report \n");

                    printf("Enter Total Fee: ");
                    scanf("%f", &totalFee);

                    printf("Enter Paid Amount: ");
                    scanf("%f", &paidFee);

                    if (totalFee >= 0 &&
                        paidFee >= 0 &&
                        paidFee <= totalFee) {

                        remainingFee = totalFee - paidFee;

                        printf("Total Fee: %.2f\n", totalFee);
                        printf("Paid: %.2f\n", paidFee);
                        printf("Due: %.2f\n", remainingFee);

                    } else {

                        printf("Invalid fee data.\n");
                    }

                    break;

                case 4:

                    printf("\n Complaint Report \n");

                    printf("Enter Complaint ID: ");
                    scanf("%d", &complaintID);

                    if (complaintID > 0) {

                        printf("Complaint ID: %d\n", complaintID);
                        printf("Status: UNDER REVIEW\n");

                    } else {

                        printf("Invalid Complaint ID.\n");
                    }

                    break;

                default:

                    printf("\nInvalid Report choice.\n");
            }

            break;

        case 7:

            printf("\nThank you for using the Hostel Management System.\n");
            printf("Program terminated successfully.\n");

            break;

        default:

            printf("\nInvalid Main Menu choice!\n");
            printf("Please select a number from 1 to 7.\n");
    }

    return 0;
}