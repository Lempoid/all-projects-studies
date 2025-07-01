"""Simple password validation example.

Checks that the supplied password is at least eight characters long and
contains lower and upper case letters, a digit and one special character.
"""

import re


def is_valid_password(password: str) -> bool:
    """Return ``True`` if ``password`` matches all requirements."""
    try:
        return (
            len(password) >= 8
            and re.search(r"[a-z]", password)
            and re.search(r"[A-Z]", password)
            and re.search(r"[0-9]", password)
            and re.search(r"[@#%&]", password)
        )
    except Exception as exc:  # noqa: BLE001
        print(f"exception: {exc}")
        return False


if __name__ == "__main__":  # simple demo
    print(is_valid_password("Pass1@rd"))
