        for (int i = 0; i < prefix.size(); i++)
            cout << prefix[i] << " ";
        cout << endl;
        int n = s.size();
        int ans = 0;
        while (prefix[n - 1] >= 0)
        {
            if (s[n - 1] != s[s.size() - 1])
            {
                ans = 1;
                break;
            }
            ans++;
            n = prefix[n - 1];
            cout << n << " ";
        }
        cout << endl;
        cout << ans + 1 << endl;