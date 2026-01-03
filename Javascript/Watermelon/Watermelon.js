process.stdin.on('data', c=> {
        a = Number(c);
        console.log(c > 2 && c % 2 == 0 ? "YES" : "NO");
    }
)