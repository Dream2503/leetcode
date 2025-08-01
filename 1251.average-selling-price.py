# leetcode submit region begin(Prohibit modification and deletion)
import pandas as pd


def average_selling_price(prices: pd.DataFrame, units: pd.DataFrame) -> pd.DataFrame:
    prices["key"] = 1
    units["key"] = 1
    merged = (prices.merge(units, on="key").drop("key", axis=1))
    merged = merged[(merged["product_id_x"] == merged["product_id_y"]) &
                    (merged["purchase_date"] >= merged["start_date"]) &
                    (merged["purchase_date"] <= merged["end_date"])]
    merged["revenue"] = merged["price"] * merged["units"]
    merged = merged.groupby("product_id_x", as_index=False).agg(total_revenue=("revenue", "sum"),
                                                                total_units=("units", "sum"))
    merged["average_price"] = (merged["total_revenue"] / merged["total_units"]).round(2)
    result = prices[["product_id"]].drop_duplicates().merge(merged[["product_id_x", "average_price"]], "left",
                                                            left_on="product_id", right_on="product_id_x"). \
        drop("product_id_x", axis=1)
    result["average_price"] = result["average_price"].fillna(0).round(2)
    return result[["product_id", "average_price"]]

# leetcode submit region end(Prohibit modification and deletion)
