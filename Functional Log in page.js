document.getElementById('loginForm').addEventListener('submit', function(event) {
    event.preventDefault(); // Prevent form submission

    // Clear previous error messages
    document.getElementById('usernameError').textContent = '';
    document.getElementById('passwordError').textContent = '';

    // Get input values
    const username = document.getElementById('username').value.trim();
    const password = document.getElementById('password').value.trim();

    // Validate inputs
    let valid = true;

    if (username === '') {
        document.getElementById('usernameError').textContent = 'Username is required.';
        valid = false;
    }

    if (password === '') {
        document.getElementById('passwordError').textContent = 'Password is required.';
        valid = false;
    }

    // If valid, proceed with login (this is where you would normally handle login logic)
    if (valid) {
        alert('Login successful!'); // Placeholder for successful login
        // Here you can add your login logic (e.g., API call)
    }
});

// Handle "Forgot Password" link
document.getElementById('forgotPassword').addEventListener('click', function() {
    const email = prompt('Please enter your email address for password recovery:');
    if (email) {
        // Simulate sending a password recovery email
        alert(`Password recovery email sent to ${email}.`);
    }
});

// Handle "Create Account" link
document.getElementById('createAccount').addEventListener('click', function() {
    const newUsername = prompt('Enter a username for your new account:');
    const newPassword = prompt('Enter a password for your new account:');
    if (newUsername && newPassword) {
        // Simulate account creation
        alert(`Account created for ${newUsername}.`);
    }
});