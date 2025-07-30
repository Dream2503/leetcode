# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def reformat_table(department: pd.DataFrame) -> pd.DataFrame:
    result = department.pivot(index='id', columns='month', values='revenue').reindex(
        columns=["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"])
    result.columns = [f"{col}_Revenue" for col in result.columns]
    return result.reset_index()

# leetcode submit region end(Prohibit modification and deletion)
