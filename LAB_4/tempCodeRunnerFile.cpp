    if (i <= n)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1 || j == i || i == n)
            {
                cout << "*";
            }
            else
            {
                cout << "x";
            }
        }
        cout << endl;
        RecTriangle(n, i + 1);
        for (int j = 1; j <= i; j++)
        {
            if (j == 1 || j == i || i == n)
            {
                cout << "*";
            }
            else
            {
                cout << "x";
            }
        }
        cout << endl;
    }
    else
    {
        return;
    }