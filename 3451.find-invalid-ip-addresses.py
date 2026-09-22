#
# @lc app=leetcode id=3451 lang=pandas
#
# [3451] Find Invalid IP Addresses
#

# @lc code=start
import pandas as pd


def find_invalid_ips(logs: pd.DataFrame) -> pd.DataFrame:
    res: dict[str, int] = {}

    for ip in logs["ip"]:
        octets: list[str] = ip.split('.')

        if len(octets) != 4:
            res[ip] = res.get(ip, 0) + 1

        else:
            for octet in octets:
                if not octet.isnumeric() or (int(octet) != 0 and octet.startswith('0')) or int(octet) > 255:
                    res[ip] = res.get(ip, 0) + 1
                    break

    return pd.DataFrame(res.items(), columns=["ip", "invalid_count"]).sort_values(["invalid_count", "ip"], ascending=[False, False])

# @lc code=end
