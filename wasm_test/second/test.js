// If modularized, you must invoke the factory function
Module().then(function(instance) {
    console.log("WASM is ready!");
    
    var printfunction = instance.cwrap('printshit', 'string', []);
    const button = document.getElementById("action-btn");
    
    button.addEventListener("click", () => {
        console.log(printfunction());
    });
});