const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function outputArray(arr) {
    console.log("Array elements: " + arr.join(" "));
}

function linearSearch(arr, n) {
    let found = false;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === n) {
            console.log("Entered element " + arr[i] + " found at index " + i);
            found = true;
        }
    }
    if (!found) {
        console.log("Entered element " + n + " not found in the array");
    }
}

function reverseArray(arr) {
    const reversedArr = arr.slice().reverse();
    console.log("Reversed array: " + reversedArr.join(" "));
}

function updateArray(arr) {
    const updatedArr = arr.map((element, index) => index % 2 === 0 ? element * 2 : element + 5);
    console.log("Updated array: " + updatedArr.join(" "));
}

function insertElement(arr) {
    rl.question("Enter index you want to insert element in: ", (index) => {
        rl.question("Enter element you want to insert: ", (element) => {
            arr.splice(index, 0, element);
            console.log("Array after insertion:");
            outputArray(arr);
            rl.close();
        });
    });
}

function deleteElement(arr) {
    rl.question("Enter index to be deleted: ", (index) => {
        if (index >= 0 && index < arr.length) {
            arr.splice(index, 1);
            console.log("Array after deletion:");
            outputArray(arr);
        } else {
            console.log("Invalid index");
        }
        rl.close();
    });
}

function main() {
    rl.question("Enter size of array: ", (size) => {
        let arr = [];
        console.log("Enter elements in the array:");
        let count = 0;
        const readElement = () => {
            if (count < size) {
                rl.question("", (element) => {
                    arr.push(parseInt(element));
                    count++;
                    readElement();
                });
            } else {
                outputArray(arr);
                displayMenu(arr);
            }
        };
        readElement();
    });
}

function displayMenu(arr) {
    console.log("\nMenu:");
    console.log("1. Linear Search");
    console.log("2. Reverse Array");
    console.log("3. Update Array");
    console.log("4. Insert Element");
    console.log("5. Delete Element");
    console.log("6. Exit");
    rl.question("Enter your choice: ", (choice) => {
        switch (parseInt(choice)) {
            case 1:
                rl.question("Enter n: ", (n) => {
                    linearSearch(arr, parseInt(n));
                    displayMenu(arr);
                });
                break;
            case 2:
                reverseArray(arr);
                displayMenu(arr);
                break;
            case 3:
                updateArray(arr);
                displayMenu(arr);
                break;
            case 4:
                insertElement(arr);
                break;
            case 5:
                deleteElement(arr);
                break;
            case 6:
                console.log("Exiting program.");
                rl.close();
                break;
            default:
                console.log("Invalid choice. Please enter a valid option.");
                displayMenu(arr);
                break;
        }
    });
}

main();
