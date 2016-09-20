import csv
GTIN_dict = dict({"GTIN" : list(), "AMOUNT" : list()})
GTIN_database = []
totalPrice = 0
GTIN_seperatedList = input("Enter code and amount seperated by a dash(-). Please leave a space between each GTIN-8\nExample: 11111115-2 12345675-3\nEnter Here:").split(" ")
for codeAndAmount in GTIN_seperatedList:
    if '-' in codeAndAmount:
        GTIN_dict["GTIN"].append(codeAndAmount.split('-')[0])
        GTIN_dict["AMOUNT"].append(codeAndAmount.split('-')[-1])
    else:
        print("Can't find corresponding value for " + codeAndAmount)
with open("database.csv") as file:
    print("\nFound:\n")
    print("GTIN-8\tDescription\tPrice\tQuantity")
    for row in csv.DictReader(file):
        for GTIN_input, amount_input in zip(GTIN_dict["GTIN"],GTIN_dict["AMOUNT"]):
            if GTIN_input==row["GTIN"]:
                print(row["GTIN"]+"\t"+row["DESCRIPTION"]+"\t\t"+row["PRICE"]+"\t"+amount_input)
                totalPrice+=(float(row["PRICE"])*int(amount_input))
        GTIN_database.append(row["GTIN"])
    print("\t\t\t\tTotal: "+str(totalPrice)) 
    print("\nNot found:\n")
    notFound = set(GTIN_dict["GTIN"]+GTIN_database) ^ set(GTIN_database)
    for item in notFound:
        print(item + " not found")
