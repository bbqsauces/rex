const addbutton = document.getElementById("adder")
const subbutton = document.getElementById("subtracter")
const scramblebutton = document.getElementById("scramblebutton")
const resultbox = document.getElementById("result")
const scrambledtext = document.getElementById("scrambledtext")
const logbutton = document.getElementById("logbutton")


logbutton.addEventListener("click", () => {
        console.log("hello! i work")
        logbutton.style.backgroundColor = 'red'
})

Module.onRuntimeInitialized = () => {

    addbutton.addEventListener("click", () =>{
        const result = Module._bridge_add(document.getElementById("first").value, document.getElementById("second").value);
        //console.log(result);
        resultbox.textContent = result;
    })

    subbutton.addEventListener("click", () => {
        const result = Module._bridge_sub(document.getElementById("first").value, document.getElementById("second").value);
        console.log(result);
        console.error("hi 1")
        resultbox.textContent = result;

    })

    scramblebutton.addEventListener("click", () =>{
        console.log(document.getElementById("inputstring").value)
        const scrambled = Module.ccall('bridge_scramble', 'string', ['string'], [document.getElementById("inputstring").value]);
        scrambledtext.textContent = scrambled;
    })

}