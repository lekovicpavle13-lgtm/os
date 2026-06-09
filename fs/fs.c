
#include "fs.h"
#include "kernel.h"

file_t files[MAX_FILES];

void fs_init()
{
    for (int i = 0; i < MAX_FILES; i++)
        files[i].used = 0;
}

void fs_list()
{
    print("\nFILES:\n");

    for (int i = 0; i < MAX_FILES; i++)
    {
        if (files[i].used)
        {
            print(files[i].name);
            print("\n");
        }
    }
}

void fs_create(char* name)
{
    for (int i = 0; i < MAX_FILES; i++)
    {
        if (!files[i].used)
        {
            int j = 0;
            while (name[j])
            {
                files[i].name[j] = name[j];
                j++;
            }
            files[i].name[j] = 0;

            files[i].content[0] = 0;
            files[i].used = 1;

            print("\nfile created\n");
            return;
        }
    }

    print("\ndisk full\n");
}

void fs_write(char* name, char* data)
{
    for (int i = 0; i < MAX_FILES; i++)
    {
        if (files[i].used)
        {
            int match = 1;
            for (int j = 0; name[j]; j++)
                if (files[i].name[j] != name[j]) match = 0;

            if (match)
            {
                int k = 0;
                while (data[k])
                {
                    files[i].content[k] = data[k];
                    k++;
                }
                files[i].content[k] = 0;

                print("\nwritten\n");
                return;
            }
        }
    }

    print("\nfile not found\n");
}

void fs_cat(char* name)
{
    for (int i = 0; i < MAX_FILES; i++)
    {
        if (files[i].used)
        {
            int match = 1;
            for (int j = 0; name[j]; j++)
                if (files[i].name[j] != name[j]) match = 0;

            if (match)
            {
                print("\n");
                print(files[i].content);
                print("\n");
                return;
            }
        }
    }

    print("\nfile not found\n");
}

void fs_delete(char* name)
{
    for (int i = 0; i < MAX_FILES; i++)
    {
        if (files[i].used)
        {
            int match = 1;
            for (int j = 0; name[j]; j++)
                if (files[i].name[j] != name[j]) match = 0;

            if (match)
            {
                files[i].used = 0;
                print("\ndeleted\n");
                return;
            }
        }
    }

    print("\nnot found\n");
}
