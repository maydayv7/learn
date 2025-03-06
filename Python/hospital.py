#########################################
############### Python ##################
######### Hospital Management ###########
#########################################

import csv
import os
from datetime import date


def getInt(msg):
    data = input(msg)
    try:
        return int(data)
    except ValueError:
        print('Error: Input must be an integer!')
        return getInt(msg)


def getFloat(msg):
    data = input(msg)
    try:
        return float(data)
    except ValueError:
        print('Error: Input must be an floating point value!')
        return getFloat(msg)


def uniqueID():
    file = open('Patient.csv', 'r', newline='\r\n')
    read = csv.reader(file)

    id = getInt('Enter Patient ID: ')
    exist = 0
    for record in read:
        if int(record[0]) == id:
            exist += 1
    if exist != 0:
        print('Error: Patient with ID', id, 'already exists!')
        uniqueID()
    file.close()
    return id


def newPatient():
    print("Add a new Patient Record")
    print("=========================")

    file = open('Patient.csv', 'a', newline='\r\n')
    write = csv.writer(file)

    id = uniqueID()
    name = input('Enter Patient Name: ')
    illness = input('Enter Illness: ')
    fee = getFloat('Enter Fee: ')
    doctor = input('Enter name of Doctor: ')

    print("----------------------------------------------------")

    record = [id, date.today(), name, illness, fee, doctor]
    write.writerow(record)
    file.close()
    print("Info: Patient Record Saved")


def editPatient():
    print("Modify a Patient Record")
    print("=========================")

    file_r = open('Patient.csv', 'r', newline='\r\n')
    file_w = open('temp.csv', 'a', newline='\r\n')
    read = csv.reader(file_r)
    write = csv.writer(file_w)

    id = getInt('Enter ID of Patient whose record is to be modified: ')
    exist = 0
    for record in read:
        if int(record[0]) == id:
            exist += 1
            date = record[1]
            name = record[2]
            illness = record[3]
            fee = record[4]
            doctor = record[5]

            print("-------------------------------")
            print("(1) Patient Name:", name)
            print("(2) Illness:", illness)
            print("(3) Fee:", fee)
            print("(4) Name of Doctor:", doctor)
            print("-------------------------------")

            choice = getInt("Enter your Choice: ")
            if choice == 1:
                name = input('Enter new Patient Name: ')
            elif choice == 2:
                illness = input('Enter Illness: ')
            elif choice == 3:
                fee = getFloat('Enter Fee: ')
            elif choice == 4:
                doctor = input('Enter name of Doctor: ')
            else:
                print('Info: Patient Record is unchanged!')

            record = [id, date, name, illness, fee, doctor]
            write.writerow(record)

            if 1 <= choice <= 4:
                print("Info: Patient Record Modified!")
        else:
            write.writerow(record)

    if exist == 0:
        print('Error: Patient with ID', id, 'does not exist!')

    file_r.close()
    file_w.close()
    os.remove("Patient.csv")
    os.rename("temp.csv", "Patient.csv")


def delPatient():
    print("Delete a Patient Record")
    print("=========================")

    file_r = open('Patient.csv', 'r', newline='\r\n')
    file_w = open('temp.csv', 'a', newline='\r\n')
    read = csv.reader(file_r)
    write = csv.writer(file_w)

    id = getInt('Enter ID of Patient whose record is to be deleted: ')
    exist = 0
    for record in read:
        if int(record[0]) == id:
            exist += 1
            print("-------------------------------")
            print("Day of Registration:", record[1])
            print("Patient Name:", record[2])
            print("Illness:", record[3])
            print("Fee:", record[4])
            print("Name of Doctor:", record[5])
            print("-------------------------------")

            choice = input("Do you want to delete the above record (y/n): ")
            if choice == 'y' or choice == 'Y':
                pass
                print("Info: Patient Record Deleted!")
            else:
                print('Info: Patient Record is unchanged!')
                write.writerow(record)
        else:
            write.writerow(record)

    if exist == 0:
        print('Error: Patient with ID', id, 'does not exist!')

    file_r.close()
    file_w.close()
    os.remove("Patient.csv")
    os.rename("temp.csv", "Patient.csv")


def searchPatient():
    print("Search a Patient Record")
    print("=======================")

    file = open('Patient.csv', 'r', newline='\r\n')
    read = csv.reader(file)

    id = getInt('Enter ID to search for Patient: ')
    exist = 0
    for record in read:
        if int(record[0]) == id:
            exist += 1
            print("-------------------------------")
            print("Day of Registration:", record[1])
            print("Patient Name:", record[2])
            print("Illness:", record[3])
            print("Fee:", record[4])
            print("Name of Doctor", record[5])
            print("-------------------------------")
    if exist == 0:
        print('Error: Patient with ID', id, 'does not exist!')
    file.close()


def listPatients():
    choice = 0
    while choice != 3:
        print("(1) List All Patients")
        print("(2) List Patients by Day")
        print("(3) Return to Main Menu")

        print("--------------------------------")
        choice = getInt('Enter your Choice: ')
        print("--------------------------------", end="\n")

        file = open('Patient.csv', 'r', newline='\r\n')
        read = csv.reader(file)

        if choice == 1:
            print("====================================================================================================")
            print("                                       List of All Patients")
            print("====================================================================================================")

            count = 0
            print("ID\t\tDATE\t\t\tNAME\t\tILLNESS\t\tFEE\t\tDOCTOR")
            for record in read:
                print(record[0], end="\t\t")
                print(record[1], end="\t\t")
                print(record[2], end="\t\t")
                print(record[3], end="\t\t")
                print(record[4], end="\t\t")
                print(record[5])
                count += 1
            print("----------------------------------------------------------------------------------------------------")
            print('Total: ', count, end="\n")
            break

        elif choice == 2:
            day = input('Enter Day of Registration (YYYY-MM-DD): ')
            count = 0
            for record in read:
                if record[1] == day:
                    count += 1
            if count == 0:
                print('Info: No Patients were registered on', day)
                break
            file.seek(0)

            print("=======================================================================")
            print("                   List of Patients registered on", day)
            print("=======================================================================")

            print("ID\t\tNAME\t\tILLNESS\t\tFEE\t\tDOCTOR")
            for record in read:
                if record[1] == day:
                    print(record[0], end="\t\t")
                    print(record[2], end="\t\t")
                    print(record[3], end="\t\t")
                    print(record[4], end="\t\t")
                    print(record[5])
            print(
                "-----------------------------------------------------------------------")
            print('Total: ', count, end="\n")
            break

        elif choice == 3:
            break
        else:
            print("Error: Invalid choice, please choose again")
            file.close()
            listPatients()
            break
        file.close()


def keypress():
    input("Press any key to continue...")


def menu():
    choice = 0
    while choice != 6:
        print("\n")
        print("|----------------------------|")
        print("| Hospital Management System |")
        print("| ---------------------------|")
        print('\n')

        print("=============================")
        print("            MENU")
        print("=============================")
        print("(1) Add a new Patient Record")
        print("(2) Modify Existing Patient")
        print("(3) Delete Existing Patient")
        print("(4) Search for Patient")
        print("(5) List Patients")
        print("(6) Exit")

        print("--------------------------------")
        choice = getInt('Enter your Choice: ')
        print("--------------------------------", end="\n")

        if choice == 1:
            newPatient()
            keypress()
        elif choice == 2:
            editPatient()
            keypress()
        elif choice == 3:
            delPatient()
            keypress()
        elif choice == 4:
            searchPatient()
            keypress()
        elif choice == 5:
            listPatients()
            keypress()
        elif choice == 6:
            print("System Exited...")
            break
        else:
            print("Error: Invalid choice, please choose again")


menu()
