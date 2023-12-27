#!/bin/bash

# Function to check if a user entry exists in /etc/passwords.txt
user_entry_exists() {
    grep -q "^$1:" etc/passwords.txt
}

# Function to authenticate user
authenticate_user() {
    username=$1
    entered_password=$2

    if user_entry_exists $username; then
        hashed_password=$(grep "^$username:" etc/passwords.txt | cut -d: -f2)
        
        # Adjust the comparison for $1$ format
        if [ "$(openssl passwd -1 -salt $(echo "$hashed_password" | cut -d'$' -f3) "$entered_password")" = "$hashed_password" ]; then
            return 0  # Authentication successful
        else
            return 1  # Authentication failed
        fi
    else
        return 2  # User not found
    fi
}

# Function to access the directory
access_directory() {
    username=$1
    directory="/home/youssef/Desktop/cc/users/$username"

    if [ -d "$directory" ]; then
        # Switch to the user and navigate to the directory
        sudo su - "$username" -c "cd $directory && /bin/bash"
    else
        echo "Error: Directory not found for user $username."
        exit 1
    fi
}

# Prompt for username and password
read -p "Enter username: " input_username
read -s -p "Enter password: " input_password
echo

# Authenticate the user
authenticate_user "$input_username" "$input_password"

case $? in
    0)
        echo "Authentication successful. Accessing directory..."
        access_directory "$input_username"
        ;;
    1)
        echo "Authentication failed. Exiting."
        exit 1
        ;;
    2)
        echo "Error: User not found. Exiting."
        exit 1
        ;;
esac

