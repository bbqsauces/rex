const addbutton = document.getElementById("adder")
const subbutton = document.getElementById("subtracter")
const scramblebutton = document.getElementById("scramblebutton")
const resultbox = document.getElementById("result")
const scrambledtext = document.getElementById("scrambledtext")

Module.onRuntimeInitialized = () => {

    
    addbutton.addEventListener("click", () =>{
        const result = Module._bridge_add(document.getElementById("first").value, document.getElementById("second").value);
        //console.log(result);
        resultbox.textContent = result;
    })

    subbutton.addEventListener("click", () => {
        const result = Module._bridge_sub(document.getElementById("first").value, document.getElementById("second").value);
        //console.log(result);
        resultbox.textContent = result;

    })

    scramblebutton.addEventListener("click", () =>{
        const scrambled = Module.AsciiToString(Module._bridge_scramble(document.getElementById("inputstring").value))
        scrambledtext.textContent = scrambled;
    })

}