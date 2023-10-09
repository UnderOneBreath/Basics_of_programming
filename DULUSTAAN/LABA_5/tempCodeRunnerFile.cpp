    vector<int> r;
    int nums;
    int randomNum, min = 0, max = 1024;
    srand(time(0));
    for (int i = 0; i < 10000; i++)
    {
        randomNum = (rand() % (max - min + 1)) + min;
        r.push_back(randomNum);
    }
    for (int i = 0; i < r.size(); i++)
        Ofile << r[i] << endl;

    while (Ifile >> nums)
        a.push_back(nums);