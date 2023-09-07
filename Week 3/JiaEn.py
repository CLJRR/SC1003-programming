existing_user = {
    'Test': "Test12345",
    'Jack': "Test12345",
    'Tom': 'Password1'
}


def is_strong_password(password):

    if len(password) < 8:
        return False

    check_uppercase = False
    check_lowercase = False
    check_digits = False

    for char in password:
        if char.isupper():
            check_uppercase = True
        elif char.islower():
            check_lowercase = True
        elif char.isdigit():
            check_digits = True
        if check_uppercase and check_lowercase and check_digits:
            return True
    return False


check = False
while check != True:
    # ask for username
    user = input("User registration:\nInput your user name:")
    # check if username is duped
    if user in list(existing_user):
        print("The user exists. Please choose another user name.")
    else:
        break
while check != True:
    password = input('''Input your password:
1. the password has at least one upper case letter
2. the password has at least one lower case letter
3. the password has at least one digit
''')

    if is_strong_password(password):
        print("Your Password is strong enough. User registered.")
        # add username and password to list
        existing_user[user] = password
        # print current user list
        print(existing_user)
        break
    else:
        print("Your password is weak. Please enter a new password\
         ")
