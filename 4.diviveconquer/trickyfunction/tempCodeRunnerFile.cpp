int n;
    cin>>n;
    vector<long long> a(100005, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    d[1] = a[1];
    for (int i = 2; i <= n; i++)
        d[i] = d[i - 1] + a[i];
    point p;
    vector<point> xPoints, yPoints;
    for (int i = 1; i <= n; i++)
    {
        p.x = i;
        p.y = d[i];
        xPoints.push_back(p);
        //yPoints.push_back(p);
    }
    sort(xPoints.begin(), xPoints.end(), xCompare);
    //sort(yPoints.begin(), yPoints.end(), yCompare);
    cout << minimalDistance(xPoints, 0, n);