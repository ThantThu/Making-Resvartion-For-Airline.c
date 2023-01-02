/*
Description: This is the Econo Flight Reservation.Fistly User have to Choose the function with following Menu 'A' 'B' 'C' 'D' 'E' 'F'
            'Q'.When u choose the 'A' it will show all the seats(include empty seat), When u choose the 'B' it will show empty seat.When u choose the 'C'
            it will show only assigned seats.When u choose the 'D' it will assigned the empty seats.When u choose the 'E' it will delete one record seat.
            When u choose the 'F' it will delete all seats.Finally when you press 'Q' end the program.Quit the program using file input output


Name       : Thant Si Thu
Date       : 11/29/2022

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int  Seat_ID;
    int  Marker;
    char First_Name[50];
    char Last_Name[50];
}Econo_Flight_Reservation;

void explainProg(void);
void displayMainMenu();
void Display_All_Seat_Assignments(Econo_Flight_Reservation seats[]);
void Display_Empty_Seat(Econo_Flight_Reservation seats[]);
void Display_Assigned_Seats(Econo_Flight_Reservation seats[]);
void Assigned_Customer_to_EmptySeats(Econo_Flight_Reservation seats[]);
void Delete_One_Recorded_Seat(Econo_Flight_Reservation seats[]);
void Delete_All_Seats(Econo_Flight_Reservation seats[]);
void Initial_Data(Econo_Flight_Reservation seats[]);
void Quit(Econo_Flight_Reservation seats[]);




int main(void) 
 {
    explainProg();
    system("pause");
   
    Econo_Flight_Reservation seats[12];
    int index;
    char choice_menu;
    Initial_Data(seats);
    displayMainMenu();

    FILE* fpt;
    if ((fpt = fopen("data", "rb")) == NULL) 
	{
        printf("\n\t\tCould not open the file. ");

        for (index = 0; index < 12; index++) 
		{
            seats[index].Seat_ID = index + 1;
            seats[index].Marker = 1;
            strcpy(seats[index].First_Name, "\0");
            strcpy(seats[index].Last_Name, "\0");
        }
        fpt = fopen("data", "wb+");
        fwrite(seats, sizeof(Econo_Flight_Reservation), 12, fpt);
        fclose(fpt);
    }
    else {
        fpt = fopen("data", "rb");
        fread(seats, sizeof(Econo_Flight_Reservation ), 12, fpt);
        fclose(fpt);
    }
    
    do {
        printf("\t\tEnter a letter to choose the options: ");
        scanf(" %c", &choice_menu);

        switch (choice_menu) {
        case 'a':
        case 'A':
            Display_All_Seat_Assignments(seats);
            break;

        case 'b':
        case 'B':
            Display_Empty_Seat(seats);
            break;

        case 'c':
        case 'C':
             Display_Assigned_Seats(seats);
            break;

        case 'd':
        case 'D':
            Assigned_Customer_to_EmptySeats(seats);
            break;

        case 'e':
        case 'E':
           Delete_One_Recorded_Seat(seats);
            break;

        case 'f':
        case 'F':
           Delete_All_Seats(seats);
            break;

        case 'q':
        case 'Q':
            Quit(seats);
            break;
        }
    } while (choice_menu != 'q' && choice_menu != 'Q');


        
    return 0;
}

void explainProg(void) 
{

    printf("\n\t\tThis is the seats reservation for Econo Airline .\n\t\t++++++++++++++++++++++++++++++++++++++++++++++++\n\t\t\tDisplay ALl Assignments(include Empty)\n\t\t\tDisplay only Empty seats\n\t\t\tDispaly Assigned Seats\n\t\t\tQuit using file I/O.\n");

}

void displayMainMenu() {
printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");   
 printf("--------------------------------------------------------------------------------\n");
    printf("(A) Display_All_Seat_Assignments.\n");
    printf("(B) Display_Empty_Seat.\n");
    printf("(C) Display_Assigned_Seats.\n");
    printf("(D) Assigned_Customer_to_EmptySeats.\n");
    printf("(E) Delete_One_Recorded_Seat.\n");
    printf("(F) Delete_All_Seats.\n");
    printf("(Q) Quit\n");
printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    }



void Display_All_Seat_Assignments( Econo_Flight_Reservation seats[]) {
    int index;

    printf("\n\n\t\t----------------------------------------------------------\n");
    printf("\t\t%-3s  %-15s  %-20s  %-20s\n", "Seat No.", "Marker", "First Name", "Last Name");
    printf("\t\t----------------------------------------------------------\n");

    for (index = 0; index < 12; index++) {
        printf("\t\t%5d  %9d  %19s  %19s\n", seats[index].Seat_ID + 1, seats[index].Marker, seats[index].First_Name, seats[index].Last_Name);
    }

    printf("\t\t----------------------------------------------------------\n");
}

void Display_Empty_Seat(Econo_Flight_Reservation seats[]) {
    int index;
    int Empty_Seats = 0;
    printf("\n\n\t\t-----------------------------------------------------------\n");
    printf("\t\t%-3s  %-15s  %-20s  %-20s\n", "Seat No.", "Marker", "First Name", "Last Name");
    printf("\t\t-----------------------------------------------------------\n");

    for (index = 0; index < 12; index++) {
        if (seats[index].Marker == 1) {
           Empty_Seats++;
            printf("\t\t%5d  %9d  %19s  %19s\n",seats[index].Seat_ID  + 1, seats[index].Marker, seats[index].First_Name,seats[index].Last_Name);
        }
    }

    printf("\t\t----------------------------------------------------------\n");
    printf("\t\tTotal Empty Seats: %d \n", Empty_Seats);
    printf("\t\t------------------------\n");
}

void Display_Assigned_Seats( Econo_Flight_Reservation seats[]) {
    int index;
    int Assigned_Seats = 0;

    printf("\n\n\t\t----------------------------------------------------------\n");
    printf("\t\t%-3s  %-15s  %-20s  %-20s\n", "Seat No.", "Avalibility", "First Name", "Last Name");
    printf("\t\t----------------------------------------------------------\n");

    for (index = 0; index < 12; index++) {
        if (seats[index].Marker == 0) {
              Assigned_Seats++;;
            printf("\t\t%5d  %9d  %19s  %19s\n", seats[index].Seat_ID + 1, seats[index].Marker ,seats[index].First_Name, seats[index].Last_Name);
        }
    }

    printf("\t\t----------------------------------------------------------\n");
    printf("\t\tTotal Assigned Seats : % d \n", Assigned_Seats);
    printf("\t\t------------------------\n");
}

void Assigned_Customer_to_EmptySeats( Econo_Flight_Reservation seats[])
{

    int index;

    for (index = 0; index < 12; index++) {

        if (seats[index].Marker == 1) {

            printf("\n\t\tFirst Name: ");
            scanf(" %s", seats[index].First_Name);

            printf("\t\tLast Name: ");
            scanf(" %s", seats[index].Last_Name);

            seats[index].Marker = 0;

            printf("\t\tYou were assigned seat Number %d\n", index + 1);
            return;
        }
    }

    printf("Sorry, All the seats are occupied!");
}

void Delete_One_Recorded_Seat(Econo_Flight_Reservation seats[]) {
  
    int num= 0;
    int index;
    Display_Assigned_Seats(seats);

    printf("\n\t\tPlease enter the seat number you want to delete: ");
    scanf(" %d", &num);

    for (index = 0; index < 12; index++)
    {
        if (seats[index].Seat_ID== num)
        {
            seats[index - 1].Marker = 1;
            seats[index - 1].First_Name[0] ='\0';
            seats[index - 1].Last_Name[0] = '\0';
        
        }
    }
    printf("\n\t\tThe seat number %d is successfully deleted from the assignment.\n", num);
}

void Initial_Data(Econo_Flight_Reservation seats[])
{
    int index;

    for (index = 0; index < 12; index++) {
        seats[index].Seat_ID = index;
        seats[index].Marker = 0;
        strcpy(seats[index].First_Name, " ");
        strcpy(seats[index].Last_Name, " ");
    }
}


void Delete_All_Seats(Econo_Flight_Reservation seats[]) {
    Initial_Data(seats);
    printf("\t\tSuccessfully Deleted All The Seats\n");
}

void Quit(Econo_Flight_Reservation seats[]) {
    FILE* fpt;
    fpt = fopen("data", "wb+");
    fwrite(seats, sizeof(Econo_Flight_Reservation), 12, fpt);
    fclose(fpt);
    exit(0);
}

