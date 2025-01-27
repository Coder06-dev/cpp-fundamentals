#pragma once

int NWD(int lhs, int rhs) {
    int x = 0;
    lhs = abs(lhs);
    rhs = abs(rhs);
    while (rhs) {
        x = rhs;
        rhs = lhs % rhs;
        lhs = x;
    }
    return lhs;
}

int NWW(int lhs, int rhs) {
    lhs = abs(lhs);
    rhs = abs(rhs);
    if (lhs == 0 || rhs == 0)
        return 0;
    else
        return ((lhs * rhs) / NWD(lhs, rhs));
}
