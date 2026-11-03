
inputimage = document.querySelector("#bmpinput")
button = document.getElementById("invertButton")

console.log("hi")
Module.onRuntimeInitialized = () => {
    console.log("loaded!")
    inputimage.addEventListener('change', (e) => {
        const file = e.target.files[0];
        if (!file) return;

        
        document.getElementById("originalPreview").src = URL.createObjectURL(file);

        const reader = new FileReader();
        reader.onload = (event) => {
            uploadedFileBytes = new Uint8Array(event.target.result);
            button.disabled = false; // Enable processing button
        };
        reader.readAsArrayBuffer(file);
    });

    button.addEventListener('click', () => {
        console.log("hi")
        if (!uploadedFileBytes) return;

        // 1. Create a fresh instance of your C++ vector object
        const inputVector = new Module.VectorBytes();

        // 2. Safely feed the bytes into it one by one
        uploadedFileBytes.forEach(byte => inputVector.push_back(byte));

        // 3. Run your C++ function
        const outputVector = Module.invertImageBuffer(inputVector);

        // 4. Extract the output bytes back out into JavaScript
        const size = outputVector.size();
        const resultBytes = new Uint8Array(size);
        for (let i = 0; i < size; i++) {
            console.log(i)
            resultBytes[i] = outputVector.get(i);
        }

        // 5. Display the output image on your webpage
        const imageFile = new Blob([resultBytes], { type: 'image/bmp' });
        if (document.getElementById("resultPreview").src.startsWith('blob:')) URL.revokeObjectURL(document.getElementById("resultPreview").src);
        document.getElementById("resultPreview").src = URL.createObjectURL(imageFile);

        // 6. Clean up the C++ memory blocks
        inputVector.delete();
        outputVector.delete();
    });


}