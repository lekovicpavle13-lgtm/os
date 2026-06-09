void run_command(char* cmd)
{
    if (cmd[0]=='h' && cmd[1]=='e')
        print("\nhelp: clear, echo\n");

    else if (cmd[0]=='c')
        clear();

    else if (cmd[0]=='e')
        print("\necho command\n");

    else
        print("\nunknown command\n");

    print("\n> ");
}

