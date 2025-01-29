#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Clear screen function for different operating systems
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Structure to store patient details
typedef struct {
    char id[10]; // Change from int to string
    char name[50];
    int age;
    char phone[10];
    char doctorName[50];
    char specialization[50];
    char appointmentDate[20];
    char appointmentTime[10];
    char room[10];
    char diseaseDescription[100];
    char medicines[200];
    char scan[50];
} Patient;

// Function declarations
void mainMenu();
void channelDoctor();
void patientExamination();
void billing();
void opd();
void namescrn();
void saveToFile(Patient p);
char* generatePatientID();
Patient getPatientDetails(char* patientID);

int patientIDCounter = 1;

int main() {

    int choice;
    namescrn();

    mainMenu();
    return 0;
}

void mainMenu() {
    int choice;

    while (1) {
        clearScreen();
        namescrn();
        printf("\n===== Hospital Management System =====\n");
        printf("1. Channel a doctor\n");
        printf("2. Consult a Doctor \n");
        printf("3. Bill\n");
        printf("4. Outpatient department (OPD)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                channelDoctor();
                break;
            case 2:
                patientExamination();
                break;
            case 3:
                billing();
                break;
            case 4:
                opd();
                break;
            case 5:
                clearScreen();
                namescrn();
                printf("Thank you for using Hospital Management System. Goodbye!\n");
                exit(0);
            default:
                namescrn();
                printf("Invalid choice. Please try again.\n");
                getchar();

        }
    }
}

void channelDoctor() {
    Patient p;
    int doctorChoice;
    int moreChoices;

    while (1) {
        clearScreen();
        namescrn();
        strcpy(p.id, generatePatientID()); // Generate patient ID

        printf("\n===== Channel a Doctor =====\n");
        printf("Available Doctors:\n");
        printf("1. Dr. Ashen Pathirathne (Cardiologist) - Room: 01\n");
        printf("2. Dr. Milinda Perera (Dermatologist) - Room: 02\n");
        printf("3. Dr. Ishan Dissanayaka (Pediatrician) - Room: 03\n");
        printf("4. Dr. Nipuna Wijenayake (Neurologist ) - Room: 04\n");
        printf("5. Dr. Sasindu Prabath (Psychiatrist) - Room: 05\n");
        printf("6. Dr. Oshan Gunawardhna (Orthopedic) - Room: 06\n");
        printf("7. Dr. Mohomad Shareef ( ENT Specialist) - Room: 07\n");
        printf("8. Dr. Saduni Pathirathne (Ophthalmologist) - Room: 08\n");
        printf("9. Dr. Mohomad Shareef (Urologist) - Room: 09\n");
        printf("10. Dr. Saduni Pathirathne (Gastroenterologist) - Room: 10\n");

        printf("Select a doctor : ");
        scanf("%d", &doctorChoice);

        switch (doctorChoice) {
            case 1:
                strcpy(p.doctorName, "Dr. Ashen Pathirathne");
                strcpy(p.specialization, "Cardiologist");
                strcpy(p.appointmentDate, "15/02/2025");
                strcpy(p.appointmentTime, "10:00 AM");
                strcpy(p.room, "01");
                break;
            case 2:
                strcpy(p.doctorName, "Dr. Milinda Perera");
                strcpy(p.specialization, "Dermatologist");
                strcpy(p.appointmentDate, "16/02/2025");
                strcpy(p.appointmentTime, "11:30 AM");
                strcpy(p.room, "02");
                break;
            case 3:
                strcpy(p.doctorName, "Dr. Ishan Dissanayaka");
                strcpy(p.specialization, "Pediatrician");
                strcpy(p.appointmentDate, "17/02/2025");
                strcpy(p.appointmentTime, "02:00 PM");
                strcpy(p.room, "03");
                break;
            case 4:
                strcpy(p.doctorName, "Dr. Nipuna Wijenayake");
                strcpy(p.specialization, "Orthopedic");
                strcpy(p.appointmentDate, "18/02/2025");
                strcpy(p.appointmentTime, "03:30 PM");
                strcpy(p.room, "04");
                break;
            case 5:
                strcpy(p.doctorName, "Dr. Sasindu Prabath");
                strcpy(p.specialization, "Cardiologist");
                strcpy(p.appointmentDate, "15/02/2025");
                strcpy(p.appointmentTime, "10:00 AM");
                strcpy(p.room, "05");
                break;
            case 6:
                strcpy(p.doctorName, "Dr. Oshan Gunawardhna");
                strcpy(p.specialization, "Cardiologist");
                strcpy(p.appointmentDate, "15/02/2025");
                strcpy(p.appointmentTime, "10:00 AM");
                strcpy(p.room, "06");
                break;
            case 7:
                strcpy(p.doctorName, "Dr. Mohomad Shareef");
                strcpy(p.specialization, "Cardiologist");
                strcpy(p.appointmentDate, "15/02/2025");
                strcpy(p.appointmentTime, "10:00 AM");
                strcpy(p.room, "07");
                break;
            case 8:
                strcpy(p.doctorName, "Dr. Saduni Pathirathne");
                strcpy(p.specialization, "Cardiologist");
                strcpy(p.appointmentDate, "15/02/2025");
                strcpy(p.appointmentTime, "10:00 AM");
                strcpy(p.room, "08");
                break;
            case 9:
                strcpy(p.doctorName, "Dr. Mohomad Shareef");
                strcpy(p.specialization, "Cardiologist");
                strcpy(p.appointmentDate, "15/02/2025");
                strcpy(p.appointmentTime, "10:00 AM");
                strcpy(p.room, "09");
                break;
            case 10:
                strcpy(p.doctorName, " Dr. Saduni Pathirathne");
                strcpy(p.specialization, "Cardiologist");
                strcpy(p.appointmentDate, "15/02/2025");
                strcpy(p.appointmentTime, "10:00 AM");
                strcpy(p.room, "10");
                break;

            default:
                printf("Invalid choice! Returning to main menu.\n");
                printf("\nPress Enter to continue...");
                getchar();
                getchar();
                return;
        }

        printf("\nEnter patient name: ");
        scanf("%s", p.name);
        printf("Enter patient age: ");
        scanf("%d", &p.age);
        printf("Enter patient phone number: ");
        scanf("%s", p.phone);

        strcpy(p.diseaseDescription, "Not examined yet");
        strcpy(p.medicines, "Not prescribed yet");
        strcpy(p.scan, "Not determined yet");

        clearScreen();
        printf("\n===== Appointment Details =====\n");
        printf("Patient ID: %s\n", p.id);
        printf("Patient Name: %s\n", p.name);
        printf("Age: %d\n", p.age);
        printf("Phone: %s\n", p.phone);
        printf("Doctor: %s\n", p.doctorName);
        printf("Specialization: %s\n", p.specialization);
        printf("Appointment Date: %s\n", p.appointmentDate);
        printf("Appointment Time: %s\n", p.appointmentTime);
        printf("Room: %s\n", p.room);

        saveToFile(p);

        printf("\nAppointment details have been saved.\n");

        printf("1. Channel Other Doctor\n");
        printf("2. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &moreChoices);

        if (moreChoices == 2) {
            return;
        } else if (moreChoices != 1) {
            printf("Invalid choice. Returning to main menu.\n");
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            return;
        }
    }
}

void patientExamination() {
    char patientID[10];
    Patient p;
    int choice;
    char buffer[256];

    while (1) {
        clearScreen();
        namescrn();
        printf("\n===== Consult a Doctor =====\n");
        printf("Enter Patient ID : ");
        scanf("%s", patientID);
        getchar();

        p = getPatientDetails(patientID);

        if (strcmp(p.id, "") == 0) {
            printf("Patient not found!\n");
            printf("\nPress Enter to continue...");
            getchar();
        } else {
            printf("\n===== Patient Details =====\n\n");
            printf("Patient ID: %s\n", p.id);
            printf("Patient Name: %s\n", p.name);
            printf("Age: %d\n", p.age);
            printf("Phone: %s\n", p.phone);
            printf("Doctor: %s\n", p.doctorName);
            printf("Specialization: %s\n", p.specialization);
            printf("Appointment Date: %s\n", p.appointmentDate);
            printf("Appointment Time: %s\n", p.appointmentTime);
            printf("Room: %s\n", p.room);

            printf("\nEnter the disease : ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            strcpy(p.diseaseDescription, buffer);

            printf("Enter medicines: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            strcpy(p.medicines, buffer);

            printf("Does the patient need a scan? (yes/no): ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0;

            if (strncmp(buffer, "yes", 3) == 0) {
                printf("Enter the scan (CT/MIR/X-Ray/PET): ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                strcpy(p.scan, buffer);
            } else {
                strcpy(p.scan, "No scan required.");
            }

            saveToFile(p);
            printf("\nThe Details have been goes to Billing Section.\n");
        }

        printf("\n \n");
        printf("1. Check Another Patient\n");
        printf("2. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 2) {
            return;
        } else if (choice != 1) {
            printf("Invalid choice. Returning to main menu.\n");
            printf("\nPress Enter to continue...");
            getchar();
            return;
        }
    }
}

void billing() {
    char patientID[10];
    Patient p;
    float medicineCost, scanCost = 0, channelCost, totalCost;
    int choice;

    while (1) {
        clearScreen();
        namescrn();
        printf("\n===== Billing Section =====\n");
        printf("Enter Patient ID for billing: ");
        scanf("%s", patientID);

        p = getPatientDetails(patientID);

        if (strcmp(p.id, "") == 0) {
            printf("Patient not found!\n");
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
        } else {
            printf("\n============================\n");
            printf("Patient ID: %s\n", p.id);
            printf("Patient Name: %s\n", p.name);
            printf("Age: %d\n", p.age);
            printf("Phone: %s\n", p.phone);
            printf("Doctor: %s\n", p.doctorName);
            printf("Specialization: %s\n", p.specialization);
            printf("Appointment Date: %s\n", p.appointmentDate);
            printf("Appointment Time: %s\n", p.appointmentTime);
            printf("Room: %s\n", p.room);

            printf("\nEnter cost of medicines (Rs): ");
            scanf("%f", &medicineCost);

            if (strcmp(p.scan, "No scan required.") != 0) {
                printf("Enter cost of scan (%s) (Rs): ", p.scan);
                scanf("%f", &scanCost);
            }

            printf("Enter channel cost (Rs): ");
            scanf("%f", &channelCost);

            totalCost = medicineCost + scanCost + channelCost;

            clearScreen();
            namescrn();

            printf("\n===== \"Health is wealth\" =====\n");
            printf("Patient ID: %s\n", p.id);
            printf("Patient Name: %s\n", p.name);
            printf("Cost of Medicines: %.2f\n", medicineCost);
            if (scanCost > 0) {
                printf("Cost of Scan (%s): %.2f\n", p.scan, scanCost);
            }
            printf("Channel Fee (Rs): %.2f\n", channelCost);
            printf("Total Fee (Rs): %.2f\n", totalCost);


        }

        printf("\n===== Options =====\n");
        printf("1. Add Another Bill\n");
        printf("2. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            return;
        } else if (choice != 1) {
            printf("Invalid choice. Returning to main menu.\n");
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            return;
        }
    }
}

void saveToFile(Patient p) {
    FILE *file = fopen("appointments.txt", "a");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    fprintf(file, "Patient ID: %s\n", p.id);
    fprintf(file, "Patient Name: %s\n", p.name);
    fprintf(file, "Age: %d\n", p.age);
    fprintf(file, "Phone: %s\n", p.phone);
    fprintf(file, "Doctor: %s\n", p.doctorName);
    fprintf(file, "Specialization: %s\n", p.specialization);
    fprintf(file, "Appointment Date: %s\n", p.appointmentDate);
    fprintf(file, "Appointment Time: %s\n", p.appointmentTime);
    fprintf(file, "Room: %s\n", p.room);
    fprintf(file, "Disease Description: %s\n", p.diseaseDescription);
    fprintf(file, "Medicines: %s\n", p.medicines);
    fprintf(file, "Scan: %s\n\n", p.scan);

    fclose(file);
}

char* generatePatientID() {
    static char id[10];
    sprintf(id, "CH%03d", patientIDCounter++); // Format ID as "CH001", "CH002", etc.
    return id;
}

Patient getPatientDetails(char* patientID) {
    FILE *file = fopen("appointments.txt", "r");
    Patient p;
    strcpy(p.id, ""); // Initialize ID to empty string

    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return p;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "Patient ID: %s", p.id) == 1) {
            if (strcmp(p.id, patientID) == 0) {
                fgets(line, sizeof(line), file); sscanf(line, "Patient Name: %[^\n]", p.name);
                fgets(line, sizeof(line), file); sscanf(line, "Age: %d", &p.age);
                fgets(line, sizeof(line), file); sscanf(line, "Phone: %[^\n]", p.phone);
                fgets(line, sizeof(line), file); sscanf(line, "Doctor: %[^\n]", p.doctorName);
                fgets(line, sizeof(line), file); sscanf(line, "Specialization: %[^\n]", p.specialization);
                fgets(line, sizeof(line), file); sscanf(line, "Appointment Date: %[^\n]", p.appointmentDate);
                fgets(line, sizeof(line), file); sscanf(line, "Appointment Time: %[^\n]", p.appointmentTime);
                fgets(line, sizeof(line), file); sscanf(line, "Room: %[^\n]", p.room);
                fgets(line, sizeof(line), file); sscanf(line, "Disease Description: %[^\n]", p.diseaseDescription);
                fgets(line, sizeof(line), file); sscanf(line, "Medicines: %[^\n]", p.medicines);
                fgets(line, sizeof(line), file); sscanf(line, "Scan: %[^\n]", p.scan);

                fclose(file);
                return p;
            }
        }
    }

    fclose(file);
    return p;
}

void opd() {
    FILE *file;
    char name[50], phone[15], disease[50], symptoms[100], medications[100], treatments[100], comeAgain[10];
    int age, choice, diseaseChoice, lastID = 0;
    char patientID[10];
    // Common Diseases with Predefined Details
    char *commonDiseases[] = {
        "Flu",
        "Cold",
        "Fever",
        "Headache",
        "Other"};
    char *predefinedMedications[] = {
        "Antiviral, Hydration, Rest",
        "Antihistamines, Decongestants",
        "Paracetamol, Rest",
        "Painkillers, Relaxation",
        "None" // Placeholder for "Other"
    };
    char *predefinedTreatments[] = {
        "Stay hydrated, Rest well, Over-the-counter medication",
        "Steam inhalation, Warm fluids, Rest",
        "Drink plenty of fluids, Stay cool, Rest",
        "Relax in a quiet space, Avoid stress",
        "None" // Placeholder for "Other"
    };
    int totalDiseases = sizeof(commonDiseases) / sizeof(commonDiseases[0]);

    // Open the prescriptions.txt file to find the last ID
    file = fopen("prescriptions.txt", "r");
    if (file != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            if (strncmp(line, "Patient ID: OPD", 15) == 0) {
                sscanf(line, "Patient ID: OPD%d", &lastID); // Extract the last patient ID
            }
        }
        fclose(file);
    }
    clearScreen();
    namescrn();

    while (1) {
        printf(" OPD Section\n");
        printf(" -----------\n\n");
        printf(" 1. New Patient\n");
        printf(" 2. Exit to Home\n");
        printf(" Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            clearScreen();
            namescrn();
            return;
        } else if (choice != 1) {
            clearScreen();
            namescrn();
            printf(" OPD Section\n");
            printf(" -----------\n\n");
            printf(" Invalid choice. Try again...\n\n");
            continue;
        }

        clearScreen();
        namescrn();
        printf(" OPD Section\n");
        printf(" -----------\n\n");
        // Generate a new Patient ID
        lastID++;
        snprintf(patientID, sizeof(patientID), "OPD%03d", lastID);

        printf(" Patient ID : %s\n", patientID);
        // Get patient details
        printf(" Enter patient name: ");
        getchar(); // Clear input buffer
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        printf(" Enter patient age: ");
        scanf("%d", &age);

        printf(" Enter phone number: ");
        scanf("%s", phone);

        // Choose a disease
        printf("\n Common Diseases:\n");
        for (int i = 0; i < totalDiseases; i++) {
            printf("   %d. %s\n", i + 1, commonDiseases[i]);
        }
        printf(" Choose a disease (1-%d): ", totalDiseases);
        scanf("%d", &diseaseChoice);

        if (diseaseChoice < 1 || diseaseChoice > totalDiseases) {
            clearScreen();
            namescrn();
            printf(" OPD Section\n");
            printf(" -----------\n\n");
            printf(" Invalid choice. Try again...\n\n");
            continue;
        }

        if (diseaseChoice == totalDiseases) {
            // Custom Disease
            printf("\n Enter disease name: ");
            getchar(); // Clear buffer
            fgets(disease, sizeof(disease), stdin);
            disease[strcspn(disease, "\n")] = 0; // Remove newline

            printf(" Enter symptoms: ");
            fgets(symptoms, sizeof(symptoms), stdin);
            symptoms[strcspn(symptoms, "\n")] = 0;

            printf(" Enter medications: ");
            fgets(medications, sizeof(medications), stdin);
            medications[strcspn(medications, "\n")] = 0;

            printf(" Enter treatments: ");
            fgets(treatments, sizeof(treatments), stdin);
            treatments[strcspn(treatments, "\n")] = 0;
        } else {
            // Predefined Disease
            strcpy(disease, commonDiseases[diseaseChoice - 1]);
            strcpy(medications, predefinedMedications[diseaseChoice - 1]);
            strcpy(treatments, predefinedTreatments[diseaseChoice - 1]);

            printf("\n Selected Disease: %s\n", disease);
            // Ask for symptoms (not predefined)
            printf(" Enter symptoms: ");
            getchar();
            fgets(symptoms, sizeof(symptoms), stdin);
            symptoms[strcspn(symptoms, "\n")] = 0;
            printf(" Medications: %s\n", medications);
            printf(" Treatments: %s\n\n", treatments);
        }

        printf(" Does the patient need to come again? (yes/no): ");
        scanf("%s", comeAgain);

        // Save data to the file
        file = fopen("prescriptions.txt", "a");
        if (file == NULL) {
            printf(" Error: Unable to save\n");
            return;
        }
        fprintf(file, "Patient ID: %s\n", patientID);
        fprintf(file, "Name: %s\n", name);
        fprintf(file, "Age: %d\n", age);
        fprintf(file, "Phone: %s\n", phone);
        fprintf(file, "Disease: %s\n", disease);
        fprintf(file, "Symptoms: %s\n", symptoms);
        fprintf(file, "Medications: %s\n", medications);
        fprintf(file, "Treatments: %s\n", treatments);
        fprintf(file, "Come Again: %s\n\n", comeAgain);
        fclose(file);

        printf("\n Patient data saved successfully!\n\n");
        printf(" Press Enter to continue...");
        getchar();
        getchar();
        clearScreen();
        namescrn();
    }
}

void namescrn() {
    // printf(" CARE CENTER\n");

    printf("   ____       _       ____    _____        ____   _____   _   _   _____   _____   ____  \n");
    printf("  / ___|     / \\     |  _ \\  | ____|      / ___| | ____| | \\ | | |_   _| | ____| |  _ \\ \n");
    printf(" | |        / . \\    | | \\ | | |_        | |     | |_    |  \\| |   | |   | |_    | | \\ |\n");
    printf(" | |       / / \\ \\   | |_/ | |  _|       | |     |  _|   |     |   | |   |  _|   | |_/ | \n");
    printf(" | |___   / _____ \\  |  _ <  | |___      | |___  | |___  | |\\  |   | |   | |___  |  _ < \n");
    printf("  \\____| /_/     \\_\\ |_| \\_\\ |_____|      \\____| |_____| |_| \\_|   |_|   |_____| |_| \\_\\ \n");
    printf(" ========================================================================================\n");
    printf("\n\n");
}
