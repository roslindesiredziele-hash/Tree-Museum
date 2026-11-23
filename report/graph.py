import pandas as pd
import matplotlib.pyplot as plt

# ==================================================
# Load Data
# ==================================================

df = pd.read_csv("data/benchmark.csv")

plt.style.use("default")

# ==================================================
# Graph 1
# Insertion Time vs Number of Keys
# ==================================================

plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["BSTRandomMs"],
    marker="o",
    linewidth=2,
    label="BST Random"
)

plt.plot(
    df["Size"],
    df["BSTBalancedMs"],
    marker="o",
    linewidth=2,
    label="BST Balanced"
)

plt.plot(
    df["Size"],
    df["StdSetMs"],
    marker="o",
    linewidth=2,
    label="std::set"
)

plt.title("Insertion Time vs Number of Keys")

plt.xlabel("Number of Keys")
plt.ylabel("Insertion Time (ms)")

plt.grid(True, alpha=0.3)

plt.legend()

plt.tight_layout()

plt.savefig(
    "report/insertion_time.png",
    dpi=300
)

# ==================================================
# Graph 2
# Tree Height vs Number of Keys
# ==================================================

plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["BSTRandomHeight"],
    marker="o",
    linewidth=2,
    label="BST Random"
)

plt.plot(
    df["Size"],
    df["BSTBalancedHeight"],
    marker="o",
    linewidth=2,
    label="BST Balanced"
)

plt.title("Tree Height vs Number of Keys")

plt.xlabel("Number of Keys")
plt.ylabel("Height")

plt.grid(True, alpha=0.3)

plt.legend()

plt.tight_layout()

plt.savefig(
    "report/tree_height.png",
    dpi=300
)

# ==================================================
# Graph 3
# Deletion Time vs Number of Keys
# ==================================================

plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["BSTDeleteMs"],
    marker="o",
    linewidth=2,
    label="BST Delete"
)

plt.plot(
    df["Size"],
    df["StdSetDeleteMs"],
    marker="o",
    linewidth=2,
    label="std::set Delete"
)

plt.title("Deletion Time vs Number of Keys")

plt.xlabel("Number of Keys")
plt.ylabel("Deletion Time (ms)")

plt.grid(True, alpha=0.3)

plt.legend()

plt.tight_layout()

plt.savefig(
    "report/deletion_time.png",
    dpi=300
)

print("Graphs saved to report/")

plt.show()