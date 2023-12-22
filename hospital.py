#########################################
############### Python ##################
######### Hospital Management ###########
#########################################

import csv
import os


def uniqueID():
    f = open('Patient.csv', 'r', newline='\r\n')
    s = csv.reader(f)

    id = int(input('Enter Patient ID: '))
    exist = 0
    for rec in s:
        if int(rec[0]) == id:
            exist += 1
    if exist != 0:
        print('Patient with ID', id, 'already exists!')
        uniqueID()

    f.close()
    return id


def newPatient():
    print("Add a new Patient Record")
    print("=========================")

    f = open('Patient.csv', 'a', newline='\r\n')
    s = csv.writer(f)

    id = uniqueID()
    name = input('Enter Patient Name: ')
    illness = input('Enter Illness: ')
    fee = float(input('Enter Fee: '))
    doctor = input('Enter name of Doctor: ')

    print("----------------------------------------------------")

    rec = [id, name, illness, fee, doctor]
    s.writerow(rec)
    f.close()
    print("Patient Record Saved")
    input("Press any key to continue...")


def editPatient():
    print("Modify a Patient Record")
    print("=========================")

    f = open('Patient.csv', 'r', newline='\r\n')
    f1 = open('temp.csv', 'a', newline='\r\n')
    s = csv.reader(f)
    s1 = csv.writer(f1)

    id = int(input('Enter ID of Patient whose record is to be modified: '))
    exist = 0
    for rec in s:
        if int(rec[0]) == id:
            exist += 1
            name = rec[1]
            illness = rec[2]
            fee = rec[3]
            doctor = rec[4]

            print("-------------------------------")
            print("(1) Patient Name:", name)
            print("(2) Illness:", illness)
            print("(3) Fee:", fee)
            print("(4) Name of Doctor:", doctor)
            print("-------------------------------")

            choice = int(input("Enter your Choice: "))
            if choice == 1:
                name = input('Enter new Patient Name: ')
            elif choice == 2:
                illness = input('Enter Illness: ')
            elif choice == 3:
                fee = float(input('Enter Fee: '))
            elif choice == 4:
                doctor = input('Enter name of Doctor: ')
            else:
                print('Patient Record is unchanged!')

            rec = [id, name, illness, fee, doctor]
            s1.writerow(rec)

            if 1 <= choice <= 4:
                print("Patient Record Modified!")
        else:
            s1.writerow(rec)

    if exist == 0:
        print('Patient with ID', id, 'does not exist!')

    f.close()
    f1.close()
    os.remove("Patient.csv")
    os.rename("temp.csv", "Patient.csv")
    input("Press any key to continue...")


def delPatient():
    print("Delete a Patient Record")
    print("=========================")

    f = open('Patient.csv', 'r', newline='\r\n')
    f1 = open('temp.csv', 'a', newline='\r\n')
    s = csv.reader(f)
    s1 = csv.writer(f1)

    id = int(input('Enter ID of Patient whose record is to be deleted: '))
    exist = 0
    for rec in s:
        if int(rec[0]) == id:
            exist += 1
            print("-------------------------------")
            print("Patient Name:", rec[1])
            print("Illness:", rec[2])
            print("Fee:", rec[3])
            print("Name of Doctor:", rec[4])
            print("-------------------------------")

            choice = input("Do you want to delete the above record (y/n): ")
            if choice == 'y' or choice == 'Y':
                pass
                print("Patient Record Deleted!")
            else:
                s1.writerow(rec)
        else:
            s1.writerow(rec)

    if exist == 0:
        print('Patient with ID', id, 'does not exist!')

    f.close()
    f1.close()
    os.remove("Patient.csv")
    os.rename("temp.csv", "Patient.csv")
    input("Press any key to continue...")


def searchPatient():
    print("Search a Patient Record")
    print("=======================")

    f = open('Patient.csv', 'r', newline='\r\n')
    s = csv.reader(f)

    id = int(input('Enter ID to search for Patient: '))
    exist = 0
    for rec in s:
        if int(rec[0]) == id:
            exist += 1
            print("-------------------------------")
            print("Patient Name:", rec[1])
            print("Illness:", rec[2])
            print("Fee:", rec[3])
            print("Name of Doctor", rec[4])
            print("-------------------------------")
    if exist == 0:
        print('Patient with ID', id, 'does not exist!')

    f.close()
    input("Press any key to continue...")


def listPatients():
    print("=======================================================================")
    print("                         List of All Patients")
    print("=======================================================================")

    f = open('Patient.csv', 'r', newline='\r\n')
    s = csv.reader(f)
    count = 0

    print("ID\t\tNAME\t\tILLNESS\t\tFEE\t\tDOCTOR")
    for rec in s:
        print(rec[0], end="\t\t")
        print(rec[1], end="\t\t")
        print(rec[2], end="\t\t")
        print(rec[3], end="\t\t")
        print(rec[4])
        count += 1
    print("------------------------------------------------------------------------")
    print('Total: ', count, end="\n")

    f.close()
    input("Press any key to continue...")


def menu():
    choice = 0
    while choice != 6:
        print("\n")
        print("|----------------------------|")
        print("| Hospital Management System |")
        print("| ---------------------------|")
        print('\n')

        print("#############################")
        print("            MENU")
        print("#############################")
        print("(1) Add a new Patient Record")
        print("(2) Modify Existing Patient")
        print("(3) Delete Existing Patient")
        print("(4) Search for Patient")
        print("(5) List all Patients")
        print("(6) Exit")

        print("--------------------------------")
        choice = int(input('Enter your Choice: '))
        print("--------------------------------")

        if choice == 1:
            newPatient()
        elif choice == 2:
            editPatient()
        elif choice == 3:
            delPatient()
        elif choice == 4:
            searchPatient()
        elif choice == 5:
            listPatients()
        elif choice == 6:
            print("System Exited...")
            break


menu()
