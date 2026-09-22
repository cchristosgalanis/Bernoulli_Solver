import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

sns.set_theme(style="whitegrid")

try:
    df = pd.read_csv("bernoulli_polynomial_results.csv")
    df = df[df['RK4'] > 0]
except FileNotFoundError:
    print("Error: 'bernoulli_polynomial_results.csv' not found. Ensure the C++ program has been executed first.")
    exit()

# Δημιουργία παραθύρου με δύο υπο-διαγράμματα
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12, 10), sharex=True)

# Διάγραμμα 1: Μέθοδος Euler
sns.lineplot(data=df, x='x', y='Euler', color='red', linewidth=2, ax=ax1)
ax1.set_title("Euler Method Solution (Polynomial P(x) & Q(x))", fontsize=13, fontweight='bold')
ax1.set_ylabel("y(x)", fontsize=11)
ax1.set_ylim(0, 30)

# Διάγραμμα 2: Μέθοδος Runge-Kutta 4
sns.lineplot(data=df, x='x', y='RK4', color='blue', linewidth=2, ax=ax2)
ax2.set_title("Runge-Kutta 4 Solution (Polynomial P(x) & Q(x))", fontsize=13, fontweight='bold')
ax2.set_ylabel("y(x)", fontsize=11)
ax2.set_xlabel("x", fontsize=11)
ax2.set_ylim(0, 30)

plt.tight_layout()
plt.savefig("bernoulli_polynomial_comparison.png", dpi=300)
plt.show()