function showAlert(){
    alert("This is an alert Box");

}

function showConfirm(){
    let confirmRest = confirm("Do you want to prceed?");
    if (confirmResult) {
        document.getElementById("result").textContent = "You clicked OK";
    } else {
        document.getElementById("result").textContent = "You clicked Cancel";
    }
}

function showPrompt() {
    let name = prompt("Enter your name:");
    if (name !== null) {
        document.getElementById("result").textContent = "Hello, " + name + "!";
    } else {
        document.getElementById("result").textContent = "You cancelled the prompt.";
    }
}