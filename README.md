# ads-revue

Compare/contrast DSA across different languages

## TODO

* set up clang-format
* set up clang-tidy
* set up ninja + VS build flows
* Set up Elixir workflow
* Set up Rust workflow
* Set up BQN workflow

## Repo Features

### Subtree Maintenance

Currently, I use subtrees to pull in external repos. Bringing them in is simple enough.
I can use the repo URI and a tag/branch, along with squash to have one commit.

```commandline
git subtree add --prefix=cpp/doctest https://github.com/doctest/doctest.git v2.4.12 --squash
```

Interestingly, this creates a commit off the mainline branch, and merges that into your target branch.
I did not expect this:

![commit history with squashed subtree](resources/subtree-squash-merge.png)

In the future, if I want to update the subtree, I can use this command:

```commandline
git subtree pull --prefix=cpp/doctest https://github.com/doctest/doctest.git v2.4.12 --squash
```

Basically the same command, except swap `add` for `pull`.