{
  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";

  outputs = inputs:
    with inputs;
    let
      system = "x86_64-linux";

      pkgs = import nixpkgs {
        inherit system;
        config.allowUnfree = true;
      };
    in
    {
      devShells.x86_64-linux.default = pkgs.mkShell {
        LIBRARY_PATH = "${pkgs.ncurses.dev}/lib";
        nativeBuildInputs = with pkgs; [
          clang-tools
          gcc
          just
          ncurses.dev
        ];
      };
    };
}
