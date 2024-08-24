// Write a javascript program to demo local and global variables. 

let globalVariable = " I'am global variable";

let demoLocalVariable = () => {
    let localVariable = " I'am local variable";
    console.log("Inside the function");
    console.log("Global variable" , globalVariable);
    console.log("Local variable" , localVariable);
};

demoLocalVariable();

console.log("Outside function");
console.log("Global variable" , globalVariable);
try{
    console.log("Local variable" , localVariable);
}
catch(error){
    console.log("Error : ", error.message);
}