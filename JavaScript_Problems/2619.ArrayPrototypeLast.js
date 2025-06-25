// Define the prototype method
Array.prototype.last = function() {
  return this.length === 0 ? -1 : this[this.length - 1];
};

// Equivalent of 'int main()' — testing the method
function main() {
  const arr1 = [1, 2, 3];
  console.log("Last element of arr1:", arr1.last()); // Should print: 3

  const arr2 = [];
  console.log("Last element of arr2:", arr2.last()); // Should print: -1
}

// Run the main function
main();
